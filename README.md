# cajero-automatico
## Proyecto escolar. Simulación de un cajero. 

### 📓 Introducción: 
Para este ejercicio se solicitó un algoritmo que dé solución al siguiente problema:
<p>Un cajero automático contiene 50 billetes de cada una de las siguientes denominaciones: $50, $100, $200, $500 y $1,000.
Considerando que el máximo de efectivo que se puede retirar por vez es $5,000 al día.</p>
<p>
Y determinar las siguientes preguntas:
<ul>
  <li>¿Cuántas personas aproximadamente podrán retirar efectivo en un mismo día?</li>
  <li>¿Cómo podemos evitar que se terminen los billetes de una sola denominación?</li>
  <li>¿Podemos hacer que el algoritmo arroje un mensaje de error cuando ya no haya más efectivo o no se complete lo suficiente para entregar dicha cantidad?</li>
  <li>¿Es posible generar un print donde calcule la cantidad de billetes entregados y la cantidad de billetes restantes?</li>
</ul>
</p>
<hr>

### 🏧 Funcionamiento del programa: 
<p>El cajero se divide en dos secciones generales: 
<ul>
  <li> Modo cliente 🙋‍♂️</li>
  <li> Modo operador/técnico 👷‍♂️ </li>
</ul></p>

<h4>Modo Cliente 🙋‍♂️</h4>
<p>En este modo el cajero sólo permite retirar efectivo. 
  Se pueden retirar montos menores a $5,000 siempre y cuando el cajero tenga suficiente dinero. <br>

Cuando el cajero debe entregar dinero a un cliente, verificará la cantidad de billetes que tiene de cada denominación e irá eligiendo los billetes de los que tenga más cantidad. <br>
<i>Por ejemplo: Si el cliente solicita $100 y el cajero tiene más billetes de $50 que de $100, el cajero preferirá entregarle 2 billetes de $50.</i><br>
<br>Esto con la finalidad de que no se termine la cantidad de billetes de una sola denominación. El cajero trata de repartir equitativamente los billetes para que se acaben a la par. 

Si el cajero no tiene efectivo disponible, enviará un mensaje de que se encuentra deshabilitado. </p>

<h4>Modo Operador 👷‍♂️</h4>
<p>El modo operador es como un modo secreto dentro del cajero que se activa cuando se ingresa "1234" cuando el cajero solicita ingresar un número en el menú principal. 
<br>En este modo se puede: 
  <ul>
    <li>"Rellenar" el cajero con una cantidad predefinida para cada denominación de billete</li>
    <li>Contar los billetes de cada denominación que quedan en el cajero</li>
    <li>Saber la cantidad de dinero que se ha retirado</li>
    <li>Recibir un mensaje de alerta cuando la cantidad de efectivo disponible es menor o igual a de $10,000</li>
    <li>Estimar la cantidad mínima y máxima de clientes que pueden retirar con la cantidad de dinero disponible en el cajero</li>
  </ul>
</p>

<p> ⌛ Con la finalidad de simular que varios clientes retiran efectivo y poder probar las funciones del modo operador, se añadió un "modo espera" que se muestra después de realizar cualquier operación del modo cliente o el modo operador.<br>
Cuando se desee salir del programa, se debe llegar a este punto de "modo espera" y presionar la tecla 'x'. </p>

 
