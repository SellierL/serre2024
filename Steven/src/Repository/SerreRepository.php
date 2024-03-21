<?php

namespace App\Repository;

use App\Entity\Serre;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<Serre>
 *
 * @method Serre|null find($id, $lockMode = null, $lockVersion = null)
 * @method Serre|null findOneBy(array $criteria, array $orderBy = null)
 * @method Serre[]    findAll()
 * @method Serre[]    findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class SerreRepository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, Serre::class);
    }

    //    /**
    //     * @return Serre[] Returns an array of Serre objects
    //     */
    //    public function findByExampleField($value): array
    //    {
    //        return $this->createQueryBuilder('s')
    //            ->andWhere('s.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->orderBy('s.id', 'ASC')
    //            ->setMaxResults(10)
    //            ->getQuery()
    //            ->getResult()
    //        ;
    //    }

    //    public function findOneBySomeField($value): ?Serre
    //    {
    //        return $this->createQueryBuilder('s')
    //            ->andWhere('s.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->getQuery()
    //            ->getOneOrNullResult()
    //        ;
    //    }
}
