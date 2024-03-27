<?php

namespace App\Entity;

use App\Repository\CaptLuminositeRepository;
use Doctrine\DBAL\Types\Types;
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

    #[ORM\Column(type: Types::DATE_MUTABLE)]
    private ?\DateTimeInterface $date = null;

    #[ORM\Column(type: Types::TIME_MUTABLE)]
    private ?\DateTimeInterface $heure = null;

    #[ORM\ManyToOne(inversedBy: 'captLuminosites')]
    #[ORM\JoinColumn(nullable: false)]
    private ?serre $serre = null;

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

    public function getDate(): ?\DateTimeInterface
    {
        return $this->date;
    }

    public function setDate(\DateTimeInterface $date): static
    {
        $this->date = $date;

        return $this;
    }

    public function getHeure(): ?\DateTimeInterface
    {
        return $this->heure;
    }

    public function setHeure(\DateTimeInterface $heure): static
    {
        $this->heure = $heure;

        return $this;
    }

    public function getSerre(): ?serre
    {
        return $this->serre;
    }

    public function setSerre(?serre $serre): static
    {
        $this->serre = $serre;

        return $this;
    }
}
