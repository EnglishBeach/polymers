{ v_0[0] * 1000.0 * (f[0] + -1 * f[0]) } * dx(<Mesh #0>[everywhere], {})
  +  {
    -1 * (
      (
          ({ A | A_{i_{12}} = (grad(f[1]))[i_{12}] * f[0] * 0.01 * exp(-1 * f[1] / 0.13) }) 
        + ({ A | A_{i_{11}} = (grad(f[1]))[i_{11}] * -0.001 * f[0] }) 
        + ({ A | A_{i_{10}} = (grad(f[0]))[i_{10}] * f[1] * -1 * 0.01 * exp(-1 * f[1] / 0.13) }) 
        + ({ A | A_{i_8} = -0.001 * (grad(f[0]))[i_8] }) 
        + ({ A | A_{i_9} = (grad(f[0]))[i_9] * 0.001 * f[1] })
      ) 
  : (grad(v_0[0]))
    ) 
  } * dx(<Mesh #0>[everywhere], {})

  +  { v_0[1] * 1000.0 * (f[1] + -1 * f[1]) 
  } * dx(<Mesh #0>[everywhere], {})

  +  { 
    -1 * (
      (
          ({ A | A_{i_{17}} = (grad(f[0]))[i_{17}] * f[1] * 0.01 * exp(-1 * f[1] / 0.13) }) 
        + ({ A | A_{i_{16}} = (grad(f[0])) [i_{16}] * f[1] * -1 * 0.01 * exp(-1 * f[1] / 0.13) }) 
        + ({ A | A_{i_{15}} = (grad(f[1]))[i_{15}] * f[0] * -1 * 0.01 * exp(-1 * f[1] / 0.13) }) 
        + ({ A | A_{i_{13}} = (grad(f[1]))[i_{13}] * -1 * 0.01 * exp(-1 * f[1] / 0.13) }) 
        + ({ A | A_{i_{14}} = (grad(f[1]))[i_{14}] * f[0] * 0.01 * exp(-1 * f[1] / 0.13) })
      ) . (grad(v_0[1]))
    ) 
  } * dx(<Mesh #0>[everywhere], {})
  +  {
      v_0[1] * -1 
      * (((x[0]) <= (0.3)) ? (1) : (0)) 
      * (((x[0]) >= (0.1)) ? (1) : (0)) 
      * 4 * (1 + -1 * f[1] + -1 * f[0]) 
      * (
        -1 * ln((1 + -1 * f[1] + -1 * f[0]) / (1 + -1 * f[0]))
        ) ** 0.75 
  } * dx(<Mesh #0>[everywhere], {})

  +  { 0 } * ds(<Mesh #0>[everywhere], {})
  +  { 0 } * ds(<Mesh #0>[everywhere], {})



{ u * 1000.0 * (P -P) } * dx
  +  { -((
( grad(N) * P * E_NP ) + 
( grad(N) * P * -E_NP ) + 
( grad(P) * N * -E_NP ) + 
( grad(P) * -E_NP ) + 
( grad(P) * N * E_NP )) . (grad(u))) } * dx


wolfram
n(0.,x)==0.2
p(0.,x)==0.001

n^(0,2)(t,x)(-0.009 p(t,x)-0.001)
+n^(1,0)(t,x)
+0.009 n(t,x) p^(0,2)(t,x)
+0.
==NeumannValue[0.,x==0\[Or]x==1.]
-4. If[0.1<x<0.3\[And]1. n(t,x)+1. p(t,x)<=0.9999,0.7 (-1. n(t,x)-1. p(t,x)+1.) (-1. log((-1. n(t,x)-1. p(t,x)+1.)/(1. -1. n(t,x))))^0.75,0.]
-0.01 p^(0,2)(t,x)
+1. p^(1,0)(t,x)
==NeumannValue[0.,x==0\[Or]x==1.]
