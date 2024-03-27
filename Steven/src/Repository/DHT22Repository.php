<?php

namespace App\Repository;

use App\Entity\DHT22;
use Doctrine\Bundle\DoctrineBundle\Repository\ServiceEntityRepository;
use Doctrine\Persistence\ManagerRegistry;

/**
 * @extends ServiceEntityRepository<DHT22>
 *
 * @method DHT22|null find($id, $lockMode = null, $lockVersion = null)
 * @method DHT22|null findOneBy(array $criteria, array $orderBy = null)
 * @method DHT22[]    findAll()
 * @method DHT22[]    findBy(array $criteria, array $orderBy = null, $limit = null, $offset = null)
 */
class DHT22Repository extends ServiceEntityRepository
{
    public function __construct(ManagerRegistry $registry)
    {
        parent::__construct($registry, DHT22::class);
    }

    //    /**
    //     * @return DHT22[] Returns an array of DHT22 objects
    //     */
    //    public function findByExampleField($value): array
    //    {
    //        return $this->createQueryBuilder('d')
    //            ->andWhere('d.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->orderBy('d.id', 'ASC')
    //            ->setMaxResults(10)
    //            ->getQuery()
    //            ->getResult()
    //        ;
    //    }

    //    public function findOneBySomeField($value): ?DHT22
    //    {
    //        return $this->createQueryBuilder('d')
    //            ->andWhere('d.exampleField = :val')
    //            ->setParameter('val', $value)
    //            ->getQuery()
    //            ->getOneOrNullResult()
    //        ;
    //    }
}
