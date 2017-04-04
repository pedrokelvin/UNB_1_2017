package questao4;


public class Questao4 {

    
    public static void main(String[] args) {
        Drone drone1, drone2, drone3, drone4;
        
        drone1 = new Drone(4, 10, 10, 150, 7, "SD", "X4 mini", "Hubsan");
        drone2 = new Drone(4, 12, 12, 1000, 20, "HD", "H5015 X4 FPV", "Hubsan");
        drone3 = new Drone(4, 16, 16, 13000, 27, "UHD", "Mavic Pro", "DJI");
        drone4 = new Drone(4, 16, 16, 13000, 15, "SUHD", "Spreading Wings", "DJI");
        
        System.out.println("Drone 1:");
        System.out.println(drone1.marca);
        System.out.println(drone1.modelo);
        System.out.println(drone1.nHelices);
        System.out.println(drone1.camera);
        System.out.println(drone1.vel_hor_max);
        System.out.println(drone1.vel_vert_max);
        System.out.println(drone1.autonomiaBateria);
        System.out.println(drone1.distanciaMaxi);
        
        System.out.println("\n");
        
        System.out.println("Drone 2:");
        System.out.println(drone2.marca);
        System.out.println(drone2.modelo);
        System.out.println(drone2.nHelices);
        System.out.println(drone2.camera);
        System.out.println(drone2.vel_hor_max);
        System.out.println(drone2.vel_vert_max);
        System.out.println(drone2.autonomiaBateria);
        System.out.println(drone2.distanciaMaxi);
        
        System.out.println("\n");
        
        System.out.println("Drone 3:");
        System.out.println(drone3.marca);
        System.out.println(drone3.modelo);
        System.out.println(drone3.nHelices);
        System.out.println(drone3.camera);
        System.out.println(drone3.vel_hor_max);
        System.out.println(drone3.vel_vert_max);
        System.out.println(drone3.autonomiaBateria);
        System.out.println(drone3.distanciaMaxi);
        
        System.out.println("\n");
        
        System.out.println("Drone 4:");
        System.out.println(drone4.marca);
        System.out.println(drone4.modelo);
        System.out.println(drone4.nHelices);
        System.out.println(drone4.camera);
        System.out.println(drone4.vel_hor_max);
        System.out.println(drone4.vel_vert_max);
        System.out.println(drone4.autonomiaBateria);
        System.out.println(drone4.distanciaMaxi);
        
        
    }
    
}
