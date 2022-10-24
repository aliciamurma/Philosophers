<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl56x7ufz003509jr5i8cj5cl/project/2781000" alt="amurcia-'s 42 Philosophers Score" /></a>

MANDATORY

Uno o más filósofos se sientan en una mesa redonda, en cuyo centro se encuentra un gran bol de espaguetis.
Los filósofos solo pueden comer, pensar o dormir.
También hay tenedores en la mesa, tantos tenedores como filósofos.
Para poder comer,  los filósofos deben tomar el tenedor de la derecha y el de la izquierda, uno en cada mano.
Cuándo un filósofo termine de comer, dejará los tenedores en la mesa e inmediatamente empezará a dormir. Una vez se despierte, empezará a pensar.
La simulación se detiene cuando un filósofo muere o cuando todos los filósofos han comido determinado número de veces.

Argumentos que acepta el programa:
1: es el número de filósofos (y tenedores).
2 (milisegundos): si un filósofo no empieza a comer en este tiempo desde el comienzo de su última comida o desde el principio de la simulación, este morirá.
3: es el tiempo que gasta un filósofo para comer. Durante ese tiempo, tendrá los tenedores ocupados.
4: es el tiempo que gasta un filósofo en dormir.
5 (argumento opcional): si todos los filósofos comen al menos este número de veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá
con la muerte de un filósofo.

Cada filósofo debe ser un hilo.
Utiliza mutex para tenedores y para usar printf.
No puedes tener más de 10ms entre la muerte de un filósofo y el momento en el que imprimes su muerte.
Intenta no matar a tus pobres filósofos.

BONUS

Los tenedores están en el centro de la mesa. Su disponibilidad depende de un semáforo.
Cada filósofo debe ser un proceso, y el proceso principal no debe ser un filósofo.
