<?php

namespace App\Entity;

use App\Repository\ExperienceRepository;
use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: ExperienceRepository::class)]
class Experience
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column(length: 255, nullable: true)]
    private ?string $Description = null;

    #[ORM\Column(type: Types::DATE_MUTABLE)]
    private ?\DateTimeInterface $DateDebut = null;

    #[ORM\Column(type: Types::DATE_MUTABLE, nullable: true)]
    private ?\DateTimeInterface $DateFin = null;

    #[ORM\Column(type: Types::DATE_MUTABLE, nullable: true)]
    private ?\DateTimeInterface $HeureDebut = null;

    #[ORM\Column(type: Types::TIME_MUTABLE)]
    private ?\DateTimeInterface $HeureFin = null;

    #[ORM\Column(length: 6)]
    private ?string $TemperatureJour = null;

    #[ORM\Column(length: 6)]
    private ?string $TemperatureNuit = null;

    #[ORM\Column(length: 6)]
    private ?string $HumiditeJour = null;

    #[ORM\Column(length: 6)]
    private ?string $HumiditeNuit = null;

    #[ORM\Column(length: 6)]
    private ?string $SeuilStressHydrique = null;

    #[ORM\ManyToOne(inversedBy: 'experiences')]
    #[ORM\JoinColumn(nullable: false)]
    private ?Serre $Serre = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getDescription(): ?string
    {
        return $this->Description;
    }

    public function setDescription(?string $Description): static
    {
        $this->Description = $Description;

        return $this;
    }

    public function getDateDebut(): ?\DateTimeInterface
    {
        return $this->DateDebut;
    }

    public function setDateDebut(\DateTimeInterface $DateDebut): static
    {
        $this->DateDebut = $DateDebut;

        return $this;
    }

    public function getDateFin(): ?\DateTimeInterface
    {
        return $this->DateFin;
    }

    public function setDateFin(?\DateTimeInterface $DateFin): static
    {
        $this->DateFin = $DateFin;

        return $this;
    }

    public function getHeureDebut(): ?\DateTimeInterface
    {
        return $this->HeureDebut;
    }

    public function setHeureDebut(?\DateTimeInterface $HeureDebut): static
    {
        $this->HeureDebut = $HeureDebut;

        return $this;
    }

    public function getHeureFin(): ?\DateTimeInterface
    {
        return $this->HeureFin;
    }

    public function setHeureFin(\DateTimeInterface $HeureFin): static
    {
        $this->HeureFin = $HeureFin;

        return $this;
    }

    public function getTemperatureJour(): ?string
    {
        return $this->TemperatureJour;
    }

    public function setTemperatureJour(string $TemperatureJour): static
    {
        $this->TemperatureJour = $TemperatureJour;

        return $this;
    }

    public function getTemperatureNuit(): ?string
    {
        return $this->TemperatureNuit;
    }

    public function setTemperatureNuit(string $TemperatureNuit): static
    {
        $this->TemperatureNuit = $TemperatureNuit;

        return $this;
    }

    public function getHumiditeJour(): ?string
    {
        return $this->HumiditeJour;
    }

    public function setHumiditeJour(string $HumiditeJour): static
    {
        $this->HumiditeJour = $HumiditeJour;

        return $this;
    }

    public function getHumiditeNuit(): ?string
    {
        return $this->HumiditeNuit;
    }

    public function setHumiditeNuit(string $HumiditeNuit): static
    {
        $this->HumiditeNuit = $HumiditeNuit;

        return $this;
    }

    public function getSeuilStressHydrique(): ?string
    {
        return $this->SeuilStressHydrique;
    }

    public function setSeuilStressHydrique(string $SeuilStressHydrique): static
    {
        $this->SeuilStressHydrique = $SeuilStressHydrique;

        return $this;
    }

    public function getSerre(): ?Serre
    {
        return $this->Serre;
    }

    public function setSerre(?Serre $Serre): static
    {
        $this->Serre = $Serre;

        return $this;
    }
}
