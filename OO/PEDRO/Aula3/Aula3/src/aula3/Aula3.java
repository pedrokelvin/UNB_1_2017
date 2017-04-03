/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aula3;

import java.util.Scanner;

public class Aula3{
	public static void main(String [] args){
		Scanner teclado;			
		Turma Milton_santos;
		Aluno a1;
		teclado = new Scanner(System.in);
		Milton_santos = new Turma();
		a1 = new Aluno();	

	 	a1.nome = teclado.nextLine();
		a1.matricula = Integer.parseInt(teclado.nextLine());
		a1.email = teclado.nextLine();
		a1.Aluno(a1.nome, a1.matricula, a1.email);
								
	}
}