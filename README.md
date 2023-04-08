<html>
<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl56x7ufz003509jr5i8cj5cl/project/2781000" alt="amurcia-'s 42 Philosophers Score" /></a>
<body>
<h1>Philosophers </h1>
<h2>Mandatory </h2>
One or more philosophers sit at a round table.<br>
There is a large bowl of spaghetti in the middle of the table.<br>
The philosophers alternatively eat, think, or sleep. <br><br>
There are as many forks as philosophers. There is one fork between each pair of philosophers.<br>
A philosopher takes their right and their left forks to eat, one in each hand.<br><br>
When a philosopher has finished eating, they put their forks back on the table and start sleeping.<br>
Once awake, they start thinking again.<br><br>
The simulation stops when a philosopher dies of starvation.<br>
<br>
Arguments:
<ol>
<li>The number of philosophers (and forks).</li>
<li> (in milliseconds): If a philosopher didn’t start eating at this time since the beginning of their last meal or the beginning of the simulation, they die.
<li> (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks. </li>
<li> (in milliseconds): The time a philosopher will spend sleeping.</li>
<li> (optional argument): If all philosophers have eaten at least that number of times, the simulation stops.</li></ol>
<br>
Each philosopher must be a thread. <br>
Use mutex for forks and to use printf.<br><br>
You can't have more than 10ms between the death of a philosopher and the moment you print their death.<br><br>
I try not to kill your poor philosophers.<br>

![image](https://user-images.githubusercontent.com/102992210/197512944-13dc10d4-d55f-46cc-85e7-8b3382fcde9a.png)

# Instructions
Compile code
```shell
make
```
Ejecute the program
```shell
make run
```

<h2>Bonus</h2>

Los tenedores están en el centro de la mesa. Su disponibilidad depende de un semáforo.

Cada filósofo debe ser un proceso, y el proceso principal no debe ser un filósofo.

# Instructions
Compile code
```shell
make bonus
```
Ejecute the program
```shell
make runbonus
```
</body>
</html>
