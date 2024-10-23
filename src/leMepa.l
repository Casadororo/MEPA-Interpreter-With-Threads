/* -------------------------------------------------------------------
 *            Arquivo: leMepa.l
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 11/2015
 *      Atualizado em: [15/09/2020, 19h:39m]
 *
 * -------------------------------------------------------------------
 *   Analisador l�xico: Reconhecedor dos tokens descritos em 
 *   leMepa.y
 * ------------------------------------------------------------------- */

%{
  #include<stdio.h>
  #include<string.h>

  #include "leMepa.h"
  #include "leMepa.tab.h"

  int num_linha=1;
  void imprimeCarregamento();
%}

/* -------------------------------------------------------------------
 * Os tokens da MEPA s�o somente:
 *    - c�digos de opera��o: CRVL, INPP, etc.
 *    - R�tulos: R00, L0000, etc.
 *    - N�meros como em CRCT 2
 *    - dois pontos como em R00:
 *    - v�rgula como em CRVL 1,0
 * -------------------------------------------------------------------
 */

novaLinha [\n]
descarte [\t\r ]+
defRotulo [RL][0-9]+
defNumero [-+]?[0-9]+

%%
{novaLinha}     {num_linha++;  imprimeCarregamento();}

{descarte}

{defNumero}     { inteiro = atoi (yytext); 
                  return INTEIRO; }
{defRotulo}     { strncpy (rotulo, yytext, TAM_TOKEN);
                  return ROTULO; }   
\:              { return DOIS_PONTOS; }
\,              { return VIRGULA; }
AMEM            { instr=amem; return AMEM; }
ARMI            { instr=armi; return ARMI; }
ARMZ            { instr=armz; return ARMZ; }
CHPR            { instr=chpr; return CHPR; }
CMAG            { instr=cmag; return CMAG; }
CMDG            { instr=cmdg; return CMDG; }
CMEG            { instr=cmeg; return CMEG; }
CMIG            { instr=cmig; return CMIG; }
CMMA            { instr=cmma; return CMMA; }
CMME            { instr=cmme; return CMME; }
CONJ            { instr=conj; return CONJ; }
CRCT            { instr=crct; return CRCT; }
CREN            { instr=cren; return CREN; }
CRVI            { instr=crvi; return CRVI; }
CRVL            { instr=crvl; return CRVL; }
DISJ            { instr=disj; return DISJ; }
DIVI            { instr=divi; return DIVI; }
DMEM            { instr=dmem; return DMEM; }
DSVF            { instr=dsvf; return DSVF; }
DSVR            { instr=dsvr; return DSVR; }
DSVS            { instr=dsvs; return DSVS; }
ENPR            { instr=enpr; return ENPR; }
ENRT            { instr=enrt; return ENRT; }
IMPR            { instr=impr; return IMPR; }
INPP            { instr=inpp; return INPP; }
INVR            { instr=invr; return INVR; }
LEIT            { instr=leit; return LEIT; }
MULT            { instr=mult; return MULT; }
NADA            { instr=nada; return NADA; }
NEGA            { instr=nega; return NEGA; }
PARA            { instr=para; return PARA; }
RTPR            { instr=rtpr; return RTPR; }
SOMA            { instr=soma; return SOMA; }
SUBT            { instr=subt; return SUBT; }
CONT            { instr=cont; return CONT; /* Vector instructions */ }
ARMM            { instr=armm; return ARMM; }
CTHR            { instr=cthr; return CTHR; /* Thread instructions */}
STHR            { instr=sthr; return STHR; }
ETHR            { instr=ethr; return ETHR; }
%%

/* -------------------------------------------------------------------
 * indica progresso na leitura do arquivo. Util em programas grandes.
 * ------------------------------------------------------------------- */

int _carregaMepa = 0;
void imprimeCarregamento(){
  return;
  if (++_carregaMepa % 64 == 0)
    printf(".\n");
  else
    printf(".");
}
