#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Suma dos flotantes
 *
 * \param Primer flotante a sumar
 * \param Segundo flotante a sumar
 * \return La suma de los dos flotantes
 *
 */

float suma(float, float );

/** \brief Resta dos flotantes
 *
 * \param Primer flotante a restar
 * \param Segundo flotante que restara al primero
 * \return Resultado de la resta de flotantes
 *
 */

float resta(float, float);

/** \brief Multiplica dos flotantes recibidos
 *
 * \param Primer flotante a multiplicar
 * \param Segundo flotante, multipica al primero
 * \return Resultado de la multiplicacion
 *
 */

float producto(float, float);

/** \brief Divide dos flotantes recibidos
 *
 * \param Primer flotante a dividir
 * \param Segundo flotante, divide al primero
 * \return Resultado de la division
 *
 */

float division(float, float);

/** \brief Realiza el factorial del numero recibido
 *
 * \param Flotante para hacer el factorial
 * \return Resultado del factorial
 *
 */

float factorial(float);

/** \brief Pide un flotante por mensaje
 *
 * \param Mensaje pidiendo el ingreso de un flotante
 * \return El flotante pedido en el mensaje
 *
 */

float ingresoOperando (char []);

#endif // FUNCIONES_H_INCLUDED
