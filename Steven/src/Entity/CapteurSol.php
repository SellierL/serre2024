<?php

namespace App\Entity;

use App\Repository\CapteurSolRepository;
use Doctrine\DBAL\Types\Types;
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

    #[ORM\Column(type: Types::DATE_MUTABLE)]
    private ?\DateTimeInterface $date = null;

    #[ORM\Column(type: Types::TIME_MUTABLE)]
    private ?\DateTimeInterface $heure = null;

    #[ORM\ManyToOne(inversedBy: 'capteurSols')]
    #[ORM\JoinColumn(nullable: false)]
    private ?serre $serre = null;

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
