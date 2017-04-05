package questao5;


public class Drone {
    
    int nHelices,vel_vert_max, vel_hor_max; 
    String camera, modelo, marca;
    boolean gravacao = false;
    
    Drone(){
        
    }
    
    Drone(int n, int velV, int velH, int d, int a, String c, String m, String marc){
        nHelices = n;
        vel_vert_max = velV;
        vel_hor_max = velH;
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
 
}
