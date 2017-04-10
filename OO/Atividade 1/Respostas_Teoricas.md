## Questão 1:

* classe

A classe contém atributos e métodos, que são responsáveis por descrever objetos ou mais precisamente para criar objetos. Ela é um tipo de fábrica para a construção de objetos.
* objeto

Objetos podem ser criados e destruídos do programa, e podem ser criados vários objetos com a mesma estrutura, se eles forem da mesma classe. Objeto é uma instância da classe, ou seja, a classe é uma forma para o objeto. Tratando de um bolo, a classe é a forma do bolo e o bolo é um objeto que pode ser de chocolate, laranja ou do que quer que você queira, e cada bolo que é feito é um novo objeto. 
* elementos de classe
Os elementos de uma classe são os atributos e métodos que cada classe possui.

* atributos

Atributos nada mais são do que as variáveis contidas em uma classe ou em um objeto. Como são variáveis esses valores podem ser alterados sem preocupações.
* métodos

Os metódos estão dentro de uma classe e fazem parte dos objetos. Métodos são subrotinas que tem como estrutura o modificador, o tipo de retorno e a lista de parâmetros. Métodos são responsáveis por executar mudanças nos valores dos atributos dos objetos apenas com a chamada do mesmo, não sendo necessário que a main repita várias vezes o mesmo passo. 
* método construtor padrão

O construtor padrão também é uma subrotina, porém é uma subrotina especial, com o papel de alocar memória para o objeto e inicializar os atributos, retornando a referência para o objeto. Toda classe tem um contrutor padrão assim que ela é criada, mesmo se o programador não declarar ela o sistema irá providenciar um método construtor padrão.
* método construtor alternativo

O método construtor alternativo, assim, como o padrão, também aloca um espaço na memória para o objeto, a diferença é que a inicialização dos atributos é feita de acordo com uma passagem de parâmetros. Diferente do método padrão, esse método pode atribuir quaisquer valores para os diversos atributos do objeto, bastanto apenas que sejam passados esses valores como parâmetro na chamado do método alternativo. 
* estado de um objeto

Ao conjunto de valores que os atributos de um objeto armazena em um instante, dá-se o nome de estado do objeto
* retenção de estado

Retenção de estados é uma propriedade do paradigma OO que permite aos objetos manterem os valores de seus atributos até o momento em que um estímulo externo ao objeto solicite uma alteração no valor de algum atributo.

## Questão 2:
	
	a)F
	"Dois objetos instanciados através do método construtor padrão terão o mesmo estado, entretanto, suas referências não serão iguais."
	Os objetos serem estanciados através do mesmo método construtor apenas implica em terem o mesmo estado, mas não em referenciarem o mesmo objeto.
		
	b)F
	"Uma classe pode ter vários métodos construtores alternativos para instanciação de seus objetos."
	Uma Classe pode ter quantos métodos construtores alternativos quiser.	
	
	c)V
	"Retenção de estados é uma propriedade do paradigma OO que permite aos objetos manterem os valores de seus atributos até o momento em que um estímulo externo ao objeto solicite uma alteração no valor de algum atributo."
	
	d)F
	"Em Java, o operador .(ponto) serve para acessar os métodos e os atributos de um objeto".
	A sentença é auto explicativa. 
	
	e)F
	"Métodos destrutores são aqueles métodos que são chamados explicitamente pelo algoritmo para destruir objetos e liberar os espaços que eles ocupam em memória. Em Java não existe métodos destrutores, e sim o que acontece é o desreferenciamento de um objeto, e depois o Garbage Collector passa avaliando a memória e é executado, destruindo esse objeto. O método finalize() é implementado em cada Classe e é chamado assim que o GC está quase destruindo o objeto, ai ele executa as ultimas instruções antes de destrui-lo."

## Questão 3 (Programação)

## Questão 4 (Programação)

## Questão 5 (Programação)

## Questão 6
	
	a) Não. Elas são instanciadas pela mesma classe mas não referenciam o mesmo objeto.
	
	b)
	Estado de q1 
		a1 = 0;
		a2 = 0.0;
		a3 = null;
		a4 = false;
	
	Estado de q2 
		a1 = 0
		a2 = 0.0
		a3 = null 
		a4 = false
	Estado de q3
		a1 = 1
		a2 = 1.0
		a3 = "null" 
		a4 = false	
	
	c)
	false (ele se referencia a objetos diferentes)
	true 
	false (o q1.a3 é uma string)
	true	
	true
	false (novamente, eles não referenciam para o mesmo objeto também)

## Questão 7

## Questão 8

## Questão 9

## Questão 10

###a)

{% highlight java %}
package questão.pkg10;


public class Turma {
    
    int codTurma;
    int numVagasTotal;
    int numVagasLivres;
    int numVagasOcupadas;
    String diasOcorrencia;
    String horariosOcorrencia;
    Disciplina disc;
    
    Turma(int c, int nT, int nL, int nO, String d, String h, Disciplina D){
        codTurma = c;
        numVagasTotal = nT;
        numVagasLivres = nL;
        numVagasOcupadas = nO;
        diasOcorrencia = d;
        horariosOcorrencia = h;
        disc = D;
    }
    
    public String obterDetalhes(){
        String resposta = "";
        resposta += "Turma " + codTurma + " da disciplina de " + disc.nome + '\n';
        resposta += "Numero total de vagas: " + numVagasTotal + '\n';
        resposta += "Numero de vagas livres: " + numVagasLivres + '\n';
        resposta += "Numero de vagas ocupadas: " + numVagasOcupadas + '\n';
        resposta += "Dias de ocorrencias: " + diasOcorrencia + '\n';
        resposta += "Horarios de ocorrencia: " + horariosOcorrencia + '\n';
             
        return resposta;
    }
}
{% endhighlight  %} 

###b)

{% highlight java %}
package questão.pkg10;


public class Questão10 {

    
    public static void main(String[] args) {
        Curso c1;
        Disciplina d1,d2;
        Turma t1, t2, t3;
        String resposta;
        
        c1 = new Curso(1, "Engenharia de Software", 240);
        
        d1 = new Disciplina(1,4, "Orientação a Objetos","FGA", c1);
        d2 = new Disciplina(2,4, "Desenvolvimento Avançado de Software","FGA", c1);
        
        t1 = new Turma(1, 46, 46, 0, "Quartas e Sextas", "12:00 - 16:00", d1);
        t2 = new Turma(1, 30, 30, 0, "Quartas e Sextas", "16:00 - 18:00", d2);
   
        System.out.println(resposta = t1.obterDetalhes());
        System.out.println("---------------------------");
        System.out.println(resposta = t2.obterDetalhes());
        
    }
    
}
{% endhighlight  %}

###c)

{% highlight java %}
package questão.pkg10;


public class Questão10 {

    
    public static void main(String[] args) {
        Curso c1;
        Disciplina d1,d2;
        Turma t1, t2, t3;
        String resposta;
        
        c1 = new Curso(1, "Engenharia de Software", 240);
        
        d1 = new Disciplina(1,4, "Orientação a Objetos","FGA", c1);
        d2 = new Disciplina(2,4, "Desenvolvimento Avançado de Software","FGA", c1);
        
        t1 = new Turma(1, 46, 46, 0, "Quartas e Sextas", "12:00 - 16:00", d1);
        t2 = new Turma(1, 30, 30, 0, "Quartas e Sextas", "16:00 - 18:00", d2);
   
        System.out.println(resposta = t1.obterDetalhes());
        System.out.println("---------------------------");
        System.out.println(resposta = t2.obterDetalhes());
        
    }
    
}
{% endhighlight  %}

###d)

{% highlight java %}
package questão.pkg10;


public class Questão10 {

    
    public static void main(String[] args) {
        Curso c1,c2;
        Disciplina d1,d2;
        Turma t1, t2, t3;
        Aluno a1, a2, a3;
        
        String resposta;
        
        c1 = new Curso(1, "Engenharia de Software", 240);
        c2 = new Curso(2, "Engenharia Eletrônica", 257);
        
        d1 = new Disciplina(1,4, "Orientação a Objetos","FGA", c1);
        d2 = new Disciplina(2,4, "Desenvolvimento Avançado de Software","FGA", c1);
        
        t1 = new Turma(1, 46, "Quartas e Sextas", "12:00 - 16:00", d1);
        t2 = new Turma(1, 30, "Quartas e Sextas", "16:00 - 18:00", d2);
   
        a1 = new Aluno("Andre", c1, 13, 23, 02, 1983);
        a2 = new Aluno("Maria", c2, 5, 27, 5, 1994);
        a3 = new Aluno("Junior", c1, 70, 16, 11, 1995);
        
        a1.Matricula(t1);
        a2.Matricula(t1);
        a3.Matricula(t2);
    }
    
}
{% endhighlight  %}


{% highlight java %}
package questão.pkg10;


public class Disciplina {
 
    int codDisciplina;
    int cargaHora;
    String nome;
    String departamento;
    Curso curso;
    
    Disciplina(int c, int ca, String n, String d, Curso cur){
        codDisciplina = c;
        cargaHora = ca;
        nome = n;
        departamento = d;
        curso = cur;
    }
    
    public String obterDetalhes() {
    String resposta = "";
    resposta += "Disciplina: " + nome + "do curso de " + curso.nomeCurso + '\n';
    resposta += "Codigo: " + codDisciplina + '\n';
    resposta += "Carga horaria: " + cargaHora;
   
    return resposta; 
  }
    
}
{% endhighlight  %}


{% highlight java %}
package questão.pkg10;


public class Curso {
  int codigo;
  String nomeCurso; 
  int cargaHoraria;
  
  Curso (int cod, String nome, int ch) {
    codigo = cod;
    nomeCurso = nome; 
    cargaHoraria = ch;
  }
  
  public String obterDetalhes() {
    String resposta = "";
    resposta += "Nome do curso: " + nomeCurso + '\n';
    resposta += "Codigo: " + codigo + '\n';
    resposta += "Carga horaria: " + cargaHoraria;
   
    return resposta; 
  }
  
  protected void finalize() {
    System.out.println("Esse objeto CURSO vai ser destruido.");
    System.out.println("Detalhes do objeto: " + '\n');
    System.out.println(obterDetalhes());
  }
    
}
{% endhighlight  %}


{% highlight java %}
package questão.pkg10;


public class Aluno {
  String nome; 
  Curso curso;
  int matricula;
  int diaNascimento, 
      mesNascimento, 
      anoNascimento;
 
  
  public Aluno(String nom, Curso cur, int mat, int dNasc, int mNasc, int aNasc) {
    nome = nom;
    curso = cur;
    matricula = mat;
    diaNascimento = dNasc; 
    mesNascimento = mNasc;
    anoNascimento = aNasc;
  }
  
  public String obterDetalhes() {
    String resposta = "";
    resposta += "Nome: " + nome + '\n';
    resposta += "Curso: " + curso + '\n';
    resposta += "Data de nascimento: " + diaNascimento + '/' + 
                                     mesNascimento + '/' + 
                                     anoNascimento;
    return resposta; 
  }
  
  public void Matricula(Turma t){
      t.Matricula();
  }
  
  protected void finalize() {
    System.out.println("Esse objeto ALUNO vai ser destruido.");
    System.out.println("Detalhes do objeto: " + '\n');
    System.out.println(obterDetalhes());
  } 
} 
{% endhighlight  %}

