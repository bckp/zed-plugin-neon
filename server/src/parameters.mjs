export function* placeholders(text) {
  for (const match of text.matchAll(/%([\w.-]*)%/g)) {
    yield { name: match[1], index: match.index, length: match[0].length };
  }
}

export function uniqueOrigins(origins) {
  const seen = new Set();
  return origins.filter(origin => {
    const key = origin.uri + ':' + origin.start;
    if (seen.has(key)) return false;
    seen.add(key);
    return true;
  });
}

export function mergeParameters(base, incoming) {
  if (!base || incoming.replace || base.kind !== 'array' || incoming.kind !== 'array') return incoming;
  const children = new Map(base.children);
  let nextIndex = Math.max(-1, ...[...children.keys()].filter(key => /^(0|[1-9]\d*)$/.test(key)).map(Number)) + 1;
  for (const [key, value] of incoming.children) {
    if (/^(0|-?[1-9]\d*)$/.test(key)) children.set(String(nextIndex++), value);
    else children.set(key, mergeParameters(children.get(key), value));
  }
  return { ...incoming, children, origins: uniqueOrigins([...base.origins, ...incoming.origins]) };
}

export function findParameter(parameters, name, seen = new Set()) {
  if (seen.has(name)) return null;
  seen.add(name);
  const keys = name.split('.');
  let current = parameters;
  for (let index = 0; index < keys.length; index++) {
    if (current?.kind !== 'array') {
      if (seen.has(current)) return null;
      seen.add(current);
      const alias = typeof current?.value === 'string' && /^%([\w.-]+)%$/.exec(current.value);
      return alias ? findParameter(parameters, alias[1] + '.' + keys.slice(index).join('.'), seen) : null;
    }
    current = current.children.get(keys[index]);
    if (!current) return null;
  }
  return current;
}

export function expandParameters(text, parameters, resolving = new Set()) {
  let result = '';
  let offset = 0;
  for (const placeholder of placeholders(text)) {
    result += text.slice(offset, placeholder.index);
    offset = placeholder.index + placeholder.length;
    if (!placeholder.name) { result += '%'; continue; }
    if (resolving.has(placeholder.name)) return null;
    const parameter = findParameter(parameters, placeholder.name);
    if (parameter?.kind !== 'value') return null;
    const value = parameter.value;
    const expanded = typeof value === 'string'
      ? expandParameters(value, parameters, new Set([...resolving, placeholder.name]))
      : value === null || value === false ? '' : value === true ? '1' : String(value);
    if (expanded === null) return null;
    result += expanded;
  }
  return result + text.slice(offset);
}
