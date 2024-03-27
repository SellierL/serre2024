<?php

namespace App\Entity;

use App\Repository\CaptLuminositeRepository;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: CaptLuminositeRepository::class)]
class CaptLuminosite
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column]
    private ?float $valeur = null;

    #[ORM\Column(length: 255)]
    private ?string $JourOuNuit = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getValeur(): ?float
    {
        return $this->valeur;
    }

    public function setValeur(float $valeur): static
    {
        $this->valeur = $valeur;

        return $this;
    }

    public function getJourOuNuit(): ?string
    {
        return $this->JourOuNuit;
    }

    public function setJourOuNuit(string $JourOuNuit): static
    {
        $this->JourOuNuit = $JourOuNuit;

        return $this;
    }
}
