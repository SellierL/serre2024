<?php

namespace App\Repository;

use App\Entity\CapteurSol;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<CapteurSol>
 *
 * @method CapteurSol|null find($id, $lockMode = null, $lockVersion = null)
 * @method CapteurSol|null findOneBy(array $criteria, array $orderBy = null)
 * @method CapteurSol[]    findAll()
 * @method CapteurSol[]    findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class CapteurSolRepository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, CapteurSol::class);
    }

    //    /**
    //     * @return CapteurSol[] Returns an array of CapteurSol objects
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

    //    public function findOneBySomeField($value): ?CapteurSol
    //    {
    //        return $this->createQueryBuilder('c')
    //            ->andWhere('c.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->getQuery()
    //            ->getOneOrNullResult()
    //        ;
    //    }
}
