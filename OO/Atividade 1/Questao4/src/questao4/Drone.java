package questao4;


public class Drone {
    int nHelices,vel_vert_max, vel_hor_max,distanciaMaxi,autonomiaBateria; 
    String camera, modelo, marca;
    boolean gravacao = false;
   
    Drone(int n, int velV, int velH, int d, int a, String c, String m, String marc){
        nHelices = n;
        vel_vert_max = velV;
        vel_hor_max = velH;
        distanciaMaxi = d;
        autonomiaBateria = a;
        camera = c;
        modelo = m;
        marca = marc;
    }
    
   /*--------------AUMENTAR E DIMINUIR VELOCIDADE VERTICAL----------*/
    public void aumentarVelVert(){ 
        vel_vert_max++;
    }
    
    public void diminuirVelVert(){ 
        if(vel_vert_max > 0)
            vel_vert_max--;
    }
    /*---------------------------------------------------------------*/
    
    
    /*--------------AUMENTAR E DIMINUIR VELOCIDADE HORIZONTAL----------*/
    public void aumentarVelHor(){
        vel_hor_max++;
    }
    
    public void diminuirVelHor(){
        if(vel_hor_max > 0)
            vel_hor_max--;
    }
    /*---------------------------------------------------------------*/
    
    
    public void IniciarGrav(){
        gravacao = !gravacao;
    }
    
    public void diminuirVelMax(){     
        if(autonomiaBateria <= 5){
            vel_vert_max = vel_vert_max/2;
            vel_hor_max = vel_hor_max/2;
        } 
    }
   
   
}
