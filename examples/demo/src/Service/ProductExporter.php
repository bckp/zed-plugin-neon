<?php

namespace App\Service;

final class ProductExporter
{
    public function __construct(private ProductImporter $importer)
    {
    }

    public static function create(ProductImporter $importer): self
    {
        return new self($importer);
    }
}
