/* Copyright 2016, Laboratorio de Microprocesadores 
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2016, Esteban Volentini <evolentini@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** \brief Breve descripción del archivo
 **
 ** Descripción completa del archivo
 **
 ** \addtogroup Modulo Nombre del módulo
 ** \brief Breve descripción del conjunto de archivos
 ** @{ */

/* === Inclusiones de cabeceras ================================================================ */
#include "unity.h"
#include "suma.h"
#include <stdio.h>

/* === Definicion y Macros ===================================================================== */
#define cantidad(variable, tipo) (sizeof(variable) / sizeof(tipo))

/* === Declaraciones de tipos de datos internos ================================================ */
typedef struct {
   int inicial;
   int operando;
   int resultado;
   int acumulado;
} ejemplo_t;

/* === Declaraciones de funciones internas ===================================================== */

/* === Definiciones de variables internas ====================================================== */
ejemplo_t EJEMPLOS[] = {
   {
      .inicial = 5, .operando = 3, .resultado = 0, .acumulado = 8,
   },{
      .inicial = 0x7FFFFFFE, .operando = 3, .resultado = 1, .acumulado = 0x7FFFFFFF,
   },{
      .inicial = 0x80000001, .operando = -3, .resultado = 1, .acumulado = 0x80000000,
   }
};

/* === Definiciones de funciones internas =====================================================- */

/* === Definiciones de funciones externas ====================================================== */
void test_suma_saturada(void) {
   char mensaje[32];

   for (int indice = 0; indice < cantidad(EJEMPLOS, ejemplo_t); indice++) {
      ejemplo_t * ejemplo = &EJEMPLOS[indice];
      sprintf(mensaje, "Ejemplo %d", indice);
      
      int suma = ejemplo->inicial;
      TEST_ASSERT_EQUAL_MESSAGE(ejemplo->resultado, acumular(&suma, ejemplo->operando), mensaje);
      TEST_ASSERT_EQUAL_MESSAGE(ejemplo->acumulado, suma, mensaje);
   }
}
/* === Ciere de documentacion ================================================================== */

/** @} Final de la definición del modulo para doxygen */
