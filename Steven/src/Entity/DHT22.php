<?php

namespace App\Entity;

use App\Repository\DHT22Repository;
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

    #[ORM\Column]
    private ?float $Humidité = null;

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

    public function getHumidité(): ?float
    {
        return $this->Humidité;
    }

    public function setHumidité(float $Humidité): static
    {
        $this->Humidité = $Humidité;

        return $this;
    }
}
