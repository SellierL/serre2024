<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

use App\Entity\Utilisateur;

use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;


class LoginController extends AbstractController
{
    #[Route('/login', name: 'app_login')]
    public function index(): Response
    {
        // creates a task object and initializes some data for this example
        $utilisateur = new Utilisateur();
        //$utilisateur->setLogin('user@example.com');
       // $utilisateur->setDueDate(new \DateTimeImmutable('tomorrow'));

        $formulaireDeLogin = $this->createFormBuilder($utilisateur)
            ->add('Login', TextType::class)
            ->add('HashMotDePasse', TextType::class,['label' => 'Mot de passe'])
            ->add('save', SubmitType::class, ['label' => 'se connecter'])
            ->getForm();
        return $this->render('login/index.html.twig', [
            'form' => $formulaireDeLogin,
        ]);
    }
}
