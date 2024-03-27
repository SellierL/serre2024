<?php

namespace App\Entity;

use App\Repository\SerreRepository;
use Doctrine\Common\Collections\ArrayCollection;
use Doctrine\Common\Collections\Collection;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: SerreRepository::class)]
class Serre
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column(length: 255)]
    private ?string $Nom = null;

    #[ORM\Column(length: 255)]
    private ?string $Description = null;

    #[ORM\OneToMany(targetEntity: Experience::class, mappedBy: 'Serre')]
    private Collection $experiences;

    #[ORM\OneToMany(targetEntity: Camera::class, mappedBy: 'serre', orphanRemoval: true)]
    private Collection $cameras;

    #[ORM\OneToMany(targetEntity: CapteurSol::class, mappedBy: 'serre', orphanRemoval: true)]
    private Collection $capteurSols;

    #[ORM\OneToMany(targetEntity: Dht22::class, mappedBy: 'serre', orphanRemoval: true)]
    private Collection $dht22s;

    #[ORM\OneToMany(targetEntity: CaptLuminosite::class, mappedBy: 'serre', orphanRemoval: true)]
    private Collection $captLuminosites;

    public function __construct()
    {
        $this->experiences = new ArrayCollection();
        $this->cameras = new ArrayCollection();
        $this->capteurSols = new ArrayCollection();
        $this->dht22s = new ArrayCollection();
        $this->captLuminosites = new ArrayCollection();
    }

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getNom(): ?string
    {
        return $this->Nom;
    }

    public function setNom(string $Nom): static
    {
        $this->Nom = $Nom;

        return $this;
    }

    public function getDescription(): ?string
    {
        return $this->Description;
    }

    public function setDescription(string $Description): static
    {
        $this->Description = $Description;

        return $this;
    }

    /**
     * @return Collection<int, Experience>
     */
    public function getExperiences(): Collection
    {
        return $this->experiences;
    }

    public function addExperience(Experience $experience): static
    {
        if (!$this->experiences->contains($experience)) {
            $this->experiences->add($experience);
            $experience->setSerre($this);
        }

        return $this;
    }

    public function removeExperience(Experience $experience): static
    {
        if ($this->experiences->removeElement($experience)) {
            // set the owning side to null (unless already changed)
            if ($experience->getSerre() === $this) {
                $experience->setSerre(null);
            }
        }

        return $this;
    }

    /**
     * @return Collection<int, Camera>
     */
    public function getCameras(): Collection
    {
        return $this->cameras;
    }

    public function addCamera(Camera $camera): static
    {
        if (!$this->cameras->contains($camera)) {
            $this->cameras->add($camera);
            $camera->setSerre($this);
        }

        return $this;
    }

    public function removeCamera(Camera $camera): static
    {
        if ($this->cameras->removeElement($camera)) {
            // set the owning side to null (unless already changed)
            if ($camera->getSerre() === $this) {
                $camera->setSerre(null);
            }
        }

        return $this;
    }

    /**
     * @return Collection<int, CapteurSol>
     */
    public function getCapteurSols(): Collection
    {
        return $this->capteurSols;
    }

    public function addCapteurSol(CapteurSol $capteurSol): static
    {
        if (!$this->capteurSols->contains($capteurSol)) {
            $this->capteurSols->add($capteurSol);
            $capteurSol->setSerre($this);
        }

        return $this;
    }

    public function removeCapteurSol(CapteurSol $capteurSol): static
    {
        if ($this->capteurSols->removeElement($capteurSol)) {
            // set the owning side to null (unless already changed)
            if ($capteurSol->getSerre() === $this) {
                $capteurSol->setSerre(null);
            }
        }

        return $this;
    }

    /**
     * @return Collection<int, Dht22>
     */
    public function getDht22s(): Collection
    {
        return $this->dht22s;
    }

    public function addDht22(Dht22 $dht22): static
    {
        if (!$this->dht22s->contains($dht22)) {
            $this->dht22s->add($dht22);
            $dht22->setSerre($this);
        }

        return $this;
    }

    public function removeDht22(Dht22 $dht22): static
    {
        if ($this->dht22s->removeElement($dht22)) {
            // set the owning side to null (unless already changed)
            if ($dht22->getSerre() === $this) {
                $dht22->setSerre(null);
            }
        }

        return $this;
    }

    /**
     * @return Collection<int, CaptLuminosite>
     */
    public function getCaptLuminosites(): Collection
    {
        return $this->captLuminosites;
    }

    public function addCaptLuminosite(CaptLuminosite $captLuminosite): static
    {
        if (!$this->captLuminosites->contains($captLuminosite)) {
            $this->captLuminosites->add($captLuminosite);
            $captLuminosite->setSerre($this);
        }

        return $this;
    }

    public function removeCaptLuminosite(CaptLuminosite $captLuminosite): static
    {
        if ($this->captLuminosites->removeElement($captLuminosite)) {
            // set the owning side to null (unless already changed)
            if ($captLuminosite->getSerre() === $this) {
                $captLuminosite->setSerre(null);
            }
        }

        return $this;
    }
}
