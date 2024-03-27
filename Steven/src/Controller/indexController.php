<?php
// src/Controller/LuckyController.php
namespace App\Controller;

use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

use Symfony\Component\HttpKernel\Attribute\MapQueryParameter;

class indexController extends AbstractController
{
    #[Route('/index')]
    public function index(): Response
    {
        $number = random_int(0, 100);

        return $this->render('index/index.html.twig', [
            'number' => $number,
        ]);
        /*
        return new Response(
            '<html><body>nombre aléatoire: '.$number.'</body></html>'
        );*/
    }

    #[Route('/page2')]
    public function page2(): Response
    {
        $number = random_int(0, 100);

        return $this->render('index/page2.html.twig', [
            'number' => $number,
        ]);
        /*
        return new Response(
            '<html><body>nombre aléatoire: '.$number.'</body></html>'
        );*/
    }

    #[Route('/experience')]
    public function experience(): Response
    {
        $number = random_int(0, 100);

        return $this->render('index/experience.html.twig', [
            'number' => $number,
        ]);
        /*
        return new Response(
            '<html><body>nombre aléatoire: '.$number.'</body></html>'
        );*/
    }

    #[Route('/creeexperience')]
    public function creeexperience(): Response
    {
        $number = random_int(0, 100);

        return $this->render('index/creeexperience.html.twig', [
            'number' => $number,
        ]);
        /*
        return new Response(
            '<html><body>nombre aléatoire: '.$number.'</body></html>'
        );*/
    }
    #[Route('/serre')]
    public function serre(): Response
    {
        $number = random_int(0, 100);

        return $this->render('index/serre.html.twig', [
            'number' => $number,
        ]);
        /*
        return new Response(
            '<html><body>nombre aléatoire: '.$number.'</body></html>'
        );*/
    }

    #[Route('/login', name: 'page-de-login')]
    public function login(): Response
    {
        // renvoi vers le controlleur login
        return $this->redirectToRoute('login');
        //return $this->render('login/index.html.twig');
    }


    #[Route('/data/temp')]
    public function temp( #[MapQueryParameter] string $temperature): Response
    {
        $humidite = random_int(0, 100);
        return $this->render('index/temp.html.twig', [
            'temp' => $temperature,
            'humidite' => $humidite,
        ]);

    }
    #[Route('/dashboard')]
    public function dashboard(): Response
    {
        $number = random_int(0, 100);

        return $this->render('index/dashboard.html.twig', [
            'number' => $number,
        ]);
        /*
        return new Response(
            '<html><body>nombre aléatoire: '.$number.'</body></html>'
        );*/
    }
}