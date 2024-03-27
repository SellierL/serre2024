<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

class ApiCameraController extends AbstractController
{
    #[Route('/api/camera', name: 'app_api_camera')]
    public function index(): Response
    {
        $x = "rrrr";
        return new JsonResponse(['x' => $x]);
    }
}
