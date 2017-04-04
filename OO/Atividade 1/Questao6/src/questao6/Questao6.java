
package questao6;


public class Questao6 {

    
    public static void main(String[] args) {
        Exemplo q1, q2, q3;
    
    q1 = new Exemplo();
    q2 = new Exemplo(0, 0.0f, null, false);
    q3 = new Exemplo(1, 1.0f, "null", false);
    
    
    System.out.println(q1 == q2);
    System.out.println(q1.a1 == q2.a1);
    System.out.println(q2.a3 == q3.a3);
    System.out.println(q1.a2 == q2.a2);
    System.out.println(q1.a4 == q3.a4);
    System.out.println(q3 == q2);
        
    }
    
}
