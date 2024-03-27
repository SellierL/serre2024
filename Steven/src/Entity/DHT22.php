<?php

namespace App\Entity;

use App\Repository\DHT22Repository;
use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: DHT22Repository::class)]
class DHT22
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column]
    private ?float $temperature = null;

    #[ORM\Column(type: Types::DATE_MUTABLE)]
    private ?\DateTimeInterface $date = null;

    #[ORM\Column(type: Types::TIME_MUTABLE)]
    private ?\DateTimeInterface $heure = null;

    #[ORM\ManyToOne(inversedBy: 'dht22s')]
    #[ORM\JoinColumn(nullable: false)]
    private ?serre $serre = null;

    #[ORM\Column(length: 6)]
    private ?string $humidite = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getTemperature(): ?float
    {
        return $this->temperature;
    }

    public function setTemperature(float $temperature): static
    {
        $this->temperature = $temperature;

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

    public function getHumidite(): ?string
    {
        return $this->humidite;
    }

    public function setHumidite(string $humidite): static
    {
        $this->humidite = $humidite;

        return $this;
    }
}
