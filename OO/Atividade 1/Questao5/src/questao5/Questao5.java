package questao5;


public class Questao5 {

    
    public static void main(String[] args) {
        
        Drone drone1 = new Drone();
        ControleRemoto c = new ControleRemoto();
        
        drone1.vel_hor_max = 1;
        
        c.x = drone1;
        
        System.out.println(drone1.vel_hor_max);
        
        c.AumentarVelHor();
        
        System.out.println(drone1.vel_hor_max);
        
        /*
        drone1.vel_hor_max = 1;
        
        System.out.println(drone1.vel_hor_max);
        
        c.AumentarVelHor(drone1);
        
        System.out.println(drone1.vel_hor_max);
        */
        
        
    }
}