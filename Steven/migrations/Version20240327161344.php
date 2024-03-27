<?php

declare(strict_types=1);

namespace DoctrineMigrations;

use Doctrine\DBAL\Schema\Schema;
use Doctrine\Migrations\AbstractMigration;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
final class Version20240327161344 extends AbstractMigration
{
    public function getDescription(): string
    {
        return '';
    }

    public function up(Schema $schema): void
    {
        // this up() migration is auto-generated, please modify it to your needs
        $this->addSql('ALTER TABLE camera ADD heure TIME NOT NULL, CHANGE image image VARCHAR(255) NOT NULL');
        $this->addSql('ALTER TABLE capt_luminosite ADD date DATE NOT NULL, ADD heure TIME NOT NULL');
        $this->addSql('ALTER TABLE capteur_sol ADD date DATE NOT NULL, ADD heure TIME NOT NULL');
        $this->addSql('ALTER TABLE dht22 ADD date DATE NOT NULL, ADD heure TIME NOT NULL');
    }

    public function down(Schema $schema): void
    {
        // this down() migration is auto-generated, please modify it to your needs
        $this->addSql('ALTER TABLE capt_luminosite DROP date, DROP heure');
        $this->addSql('ALTER TABLE camera DROP heure, CHANGE image image LONGBLOB NOT NULL');
        $this->addSql('ALTER TABLE capteur_sol DROP date, DROP heure');
        $this->addSql('ALTER TABLE dht22 DROP date, DROP heure');
    }
}
