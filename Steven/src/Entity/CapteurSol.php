<?php

namespace App\Entity;

use App\Repository\CapteurSolRepository;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: CapteurSolRepository::class)]
class CapteurSol
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column]
    private ?float $Humidite = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getHumidite(): ?float
    {
        return $this->Humidite;
    }

    public function setHumidite(float $Humidite): static
    {
        $this->Humidite = $Humidite;

        return $this;
    }
}
