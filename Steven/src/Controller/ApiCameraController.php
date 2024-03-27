<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;


use Symfony\Component\HttpFoundation\Request;
class ApiCameraController extends AbstractController
{
    #[Route('/api/camera', name: 'app_api_camera')]
    public function index(Request $request): Response
    {
        $x = "rrrr";
        $valeur = $request->getPayload()->get('valeur');
        return $this->json(['x' => 'ddfd', 'valeur' => $valeur]);
    }

    
}
