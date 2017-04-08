## Questão 1:

* classe

A classe contém atributos e métodos, que são responsáveis por descrever objetos ou mais precisamente para criar objetos. Ela é um tipo de fábrica para a construção de objetos.
* objeto

Objetos podem ser criados e destruídos do programa, e podem ser criados vários objetos com a mesma estrutura, se eles forem da mesma classe. Objeto é uma instância da classe, ou seja, a classe é uma forma para o objeto. Tratando de um bolo, a classe é a forma do bolo e o bolo é um objeto que pode ser de chocolate, laranja ou do que quer que você queira, e cada bolo que é feito é um novo objeto. 
* elementos de classe

* atributos

Atributos nada mais são do que as variáveis contidas em uma classe ou em um objeto. Como são variáveis esses valores podem ser alterados sem preocupações.
* métodos

Os metódos estão dentro de uma classe e fazem parte dos objetos. Métodos são subrotinas que tem como estrutura o modificador, o tipo de retorno e a lista de parâmetros. Métodos são responsáveis por executar mudanças nos valores dos atributos dos objetos apenas com a chamada do mesmo, não sendo necessário que a main repita várias vezes o mesmo passo. 
* método construtor padrão

O construtor padrão também é uma subrotina, porém é uma subrotina especial, com o papel de alocar memória para o objeto e inicializar os atributos, retornando a referência para o objeto. Toda classe tem um contrutor padrão assim que ela é criada, mesmo se o programador não declarar ela o sistema irá providenciar um método construtor padrão.
* método construtor alternativo
* estado de um objeto
* retenção de estado

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
{% highlight java %}

int = 10;

{% endhighlight %}
