package questao5;


public class Questao5 {

    
    public static void main(String[] args) {
        
        Drone drone1;
        
        drone1 = new Drone(4, 10, 10, 150, 7, "SD", "X4 mini", "Hubsan");
        
        drone1.aumentarVelHor(); //Aumentando a velocidade horizontal em 1 m/s
        drone1.aumentarVelVert(); //Aumentando a velocidade vertical em 1 m/s
        
        System.out.println(drone1.vel_hor_max);
        System.out.println(drone1.vel_vert_max);
        
        drone1.diminuirVelHor(); //Diminuindo a velocidade horizontal em 1 m/s
        
        System.out.println(drone1.vel_hor_max);
    }
    
}
