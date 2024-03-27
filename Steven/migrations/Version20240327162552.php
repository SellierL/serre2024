<?php

declare(strict_types=1);

namespace DoctrineMigrations;

use Doctrine\DBAL\Schema\Schema;
use Doctrine\Migrations\AbstractMigration;

/**
 * Auto-generated Migration: Please modify to your needs!
 */
final class Version20240327162552 extends AbstractMigration
{
    public function getDescription(): string
    {
        return '';
    }

    public function up(Schema $schema): void
    {
        // this up() migration is auto-generated, please modify it to your needs
        $this->addSql('ALTER TABLE camera ADD serre_id INT NOT NULL');
        $this->addSql('ALTER TABLE camera ADD CONSTRAINT FK_3B1CEE05CE732E2E FOREIGN KEY (serre_id) REFERENCES serre (id)');
        $this->addSql('CREATE INDEX IDX_3B1CEE05CE732E2E ON camera (serre_id)');
        $this->addSql('ALTER TABLE capt_luminosite ADD serre_id INT NOT NULL');
        $this->addSql('ALTER TABLE capt_luminosite ADD CONSTRAINT FK_A6082BB9CE732E2E FOREIGN KEY (serre_id) REFERENCES serre (id)');
        $this->addSql('CREATE INDEX IDX_A6082BB9CE732E2E ON capt_luminosite (serre_id)');
        $this->addSql('ALTER TABLE capteur_sol ADD serre_id INT NOT NULL');
        $this->addSql('ALTER TABLE capteur_sol ADD CONSTRAINT FK_26E6AD5DCE732E2E FOREIGN KEY (serre_id) REFERENCES serre (id)');
        $this->addSql('CREATE INDEX IDX_26E6AD5DCE732E2E ON capteur_sol (serre_id)');
        $this->addSql('ALTER TABLE dht22 ADD serre_id INT NOT NULL, ADD humidite VARCHAR(6) NOT NULL');
        $this->addSql('ALTER TABLE dht22 ADD CONSTRAINT FK_225D3C01CE732E2E FOREIGN KEY (serre_id) REFERENCES serre (id)');
        $this->addSql('CREATE INDEX IDX_225D3C01CE732E2E ON dht22 (serre_id)');
    }

    public function down(Schema $schema): void
    {
        // this down() migration is auto-generated, please modify it to your needs
        $this->addSql('ALTER TABLE capt_luminosite DROP FOREIGN KEY FK_A6082BB9CE732E2E');
        $this->addSql('DROP INDEX IDX_A6082BB9CE732E2E ON capt_luminosite');
        $this->addSql('ALTER TABLE capt_luminosite DROP serre_id');
        $this->addSql('ALTER TABLE camera DROP FOREIGN KEY FK_3B1CEE05CE732E2E');
        $this->addSql('DROP INDEX IDX_3B1CEE05CE732E2E ON camera');
        $this->addSql('ALTER TABLE camera DROP serre_id');
        $this->addSql('ALTER TABLE capteur_sol DROP FOREIGN KEY FK_26E6AD5DCE732E2E');
        $this->addSql('DROP INDEX IDX_26E6AD5DCE732E2E ON capteur_sol');
        $this->addSql('ALTER TABLE capteur_sol DROP serre_id');
        $this->addSql('ALTER TABLE dht22 DROP FOREIGN KEY FK_225D3C01CE732E2E');
        $this->addSql('DROP INDEX IDX_225D3C01CE732E2E ON dht22');
        $this->addSql('ALTER TABLE dht22 DROP serre_id, DROP humidite');
    }
}
