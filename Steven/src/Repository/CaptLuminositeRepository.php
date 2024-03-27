<?php

namespace App\Repository;

use App\Entity\CaptLuminosite;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<CaptLuminosite>
 *
 * @method CaptLuminosite|null find($id, $lockMode = null, $lockVersion = null)
 * @method CaptLuminosite|null findOneBy(array $criteria, array $orderBy = null)
 * @method CaptLuminosite[]    findAll()
 * @method CaptLuminosite[]    findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class CaptLuminositeRepository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, CaptLuminosite::class);
    }

    //    /**
    //     * @return CaptLuminosite[] Returns an array of CaptLuminosite objects
    //     */
    //    public function findByExampleField($value): array
    //    {
    //        return $this->createQueryBuilder('c')
    //            ->andWhere('c.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->orderBy('c.id', 'ASC')
    //            ->setMaxResults(10)
    //            ->getQuery()
    //            ->getResult()
    //        ;
    //    }

    //    public function findOneBySomeField($value): ?CaptLuminosite
    //    {
    //        return $this->createQueryBuilder('c')
    //            ->andWhere('c.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->getQuery()
    //            ->getOneOrNullResult()
    //        ;
    //    }
}
