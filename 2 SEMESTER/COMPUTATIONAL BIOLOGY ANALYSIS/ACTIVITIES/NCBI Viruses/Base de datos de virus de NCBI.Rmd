---
title: "Actividad colaborativa en clase | Base de datos de virus de NCBI"
author: "Diego Espejo, Daniel Esparza & Pablo Heredia"
date: "2023-04-22"
output:
  word_document: default
  html_document:
    df_print: paged
---

```{r}
library("seqinr")
library("stringr")
```

## Zika virus

## <https://www.ncbi.nlm.nih.gov/nuccore/NC_035889>

```{r}
zikaVirusFile <- read.fasta("ZIKA.fasta")
zikaVirus <- zikaVirusFile[[1]]
paste(zikaVirus, collapse='')
```

1.  ¿Cuál es el tamaño?

    ```{r}
    length(zikaVirus)
    ```

2.  ¿Cúal es la composición de nucleótidos?

    ```{r}
    (count(zikaVirus, 1) / length(zikaVirus) * 100)
    ```

3.  ¿Cuál es el contenido de GC del virus?

    ```{r}
    (count(zikaVirus, 2)[10] / length(zikaVirus) * 100)
    ```

4.  Crear una función para obtener la secuencia en complementaria, ejemplo:\
    Virus original: agttgttagt ctacgtggac cgacaagaac\
    Complementaria: tcaacaatca gatgcacctg gctgttcttg

    ```{r}
    complementaria <- function(sequence) {
      return(paste(chartr("atcg", "tagc", sequence), collapse=''))
    }

    complementaria(zikaVirus)
    ```

5.  Crear una gráfica de resumen para comparar la composición de nucleótidos:

    ```{r}
    barplot(table(zikaVirus), col = 1:4)
    ```

## SARS coronavirus

## <https://www.ncbi.nlm.nih.gov/nuccore/AY545919.1>

```{r}
coronaVirusFile <- read.fasta("SARS_coronavirus.fasta")
coronaVirus <- coronaVirusFile[[1]]
paste(coronaVirus, collapse='')
```

1.  ¿Cuál es el tamaño?

    ```{r}
    length(coronaVirus)
    ```

2.  ¿Cúal es la composición de nucleótidos?

    ```{r}
    (count(coronaVirus, 1) / length(coronaVirus) * 100)
    ```

3.  ¿Cuál es el contenido de GC?

    ```{r}
    (count(coronaVirus, 2)[10] / length(coronaVirus) * 100)
    ```

4.  Crear una función para obtener la secuencia en complementaria, ejemplo:\
    Virus original: agttgttagt ctacgtggac cgacaagaac\
    Complementaria: tcaacaatca gatgcacctg gctgttcttg

    ```{r}
    complementaria(coronaVirus)
    ```

5.  Crear una gráfica de resumen para comparar la composición de nucleótidos:

    ```{r}
    barplot(table(coronaVirus), col = 1:4)
    ```

## Wuhan seafood market pneumonia virus isolate Wuhan-Hu-1

## <https://www.ncbi.nlm.nih.gov/nuccore/NC_045512.2>

```{r}
wuhanVirusFile <- read.fasta("Wuhan-Hu-1.fasta")
wuhanVirus <- wuhanVirusFile[[1]]
paste(wuhanVirus, collapse='')
```

1.  ¿Cuál es el tamaño de la secuencia?

    ```{r}
    length(wuhanVirus)
    ```

2.  ¿Cúal es la composición de nucleótidos?

    ```{r}
    (count(wuhanVirus, 1) / length(wuhanVirus) * 100)
    ```

3.  ¿Cuál es el contenido de GC?

    ```{r}
    (count(wuhanVirus, 2)[10] / length(wuhanVirus) * 100)
    ```

4.  Crear una función para obtener la secuencia en complementaria, ejemplo:\
    Virus original: agttgttagt ctacgtggac cgacaagaac\
    Complementaria: tcaacaatca gatgcacctg gctgttcttg

    ```{r}
    complementaria(wuhanVirus)
    ```

5.  Crear una gráfica de resumen para comparar la composición de nucleótidos:

    ```{r}
    barplot(table(wuhanVirus), col = 1:4)
    ```

## Middle East respiratory syndrome coronavirus

## <https://www.ncbi.nlm.nih.gov/nuccore/NC_019843.3>

```{r}
meast_hcov_file <- read.fasta("HCoV-EMC.fasta")
meast_hcov <- meast_hcov_file[[1]]
paste(meast_hcov, collapse='')
```

1.  ¿Cuál es el tamaño de la secuencia?

    ```{r}
    length(meast_hcov)
    ```

2.  ¿Cúal es la composición de nucleótidos?

    ```{r}
    (count(meast_hcov, 1) / length(meast_hcov) * 100)
    ```

3.  ¿Cuál es el contenido de GC?

    ```{r}
    (count(meast_hcov, 2)[10] / length(meast_hcov) * 100)
    ```

4.  Crear una función para obtener la secuencia en complementaria, ejemplo:\
    Virus original: agttgttagt ctacgtggac cgacaagaac\
    Complementaria: tcaacaatca gatgcacctg gctgttcttg

    ```{r}
    complementaria(meast_hcov)
    ```

5.  Crear una gráfica de resumen para comparar la composición de nucleótidos:

    ```{r}
    barplot(table(meast_hcov), col = 1:4)
    ```

## Dengue virus 1

## <https://www.ncbi.nlm.nih.gov/nuccore/NC_001477.1>

```{r}
denguefile <- read.fasta("dengue.fasta")
dengue <- denguefile[[1]]
paste(dengue, collapse='')
```

1.  ¿Cuál es el tamaño de la secuencia?

    ```{r}
    length(dengue)
    ```

2.  ¿Cúal es la composición de nucleótidos?

    ```{r}
    (count(dengue, 1) / length(dengue) * 100)
    ```

3.  ¿Cuál es el contenido de GC?

    ```{r}
    (count(dengue, 2)[10] / length(dengue) * 100)
    ```

4.  Crear una función para obtener la secuencia en complementaria, ejemplo:\
    Virus original: agttgttagt ctacgtggac cgacaagaac\
    Complementaria: tcaacaatca gatgcacctg gctgttcttg

    ```{r}
    complementaria(dengue)
    ```

5.  Crear una gráfica de resumen para comparar la composición de nucleótidos:

    ```{r}
    barplot(table(dengue), col = 1:4)
    ```

## H1N1 - México 2009

## <https://www.ncbi.nlm.nih.gov/nuccore/CY064707>

```{r}
influenzaPB2 <- read.fasta("influenza_a.fasta")[[1]]
influenzaPB1 <- read.fasta("influenzaPB1.fasta")[[1]]
influenzaPA <- read.fasta("influenzaPA.fasta")[[1]]
influenzaHA <- read.fasta("influenzaHA.fasta")[[1]]
influenzaNP <- read.fasta("influenzaNP.fasta")[[1]]
influenzaNA <- read.fasta("influenzaNA.fasta")[[1]]
influenzaM1 <- read.fasta("influenzaM1.fasta")[[1]]
influenzaNS1 <- read.fasta("influenzaNS1.fasta")[[1]]

influenza <- c(influenzaPB2, influenzaPB1, influenzaPA, influenzaHA, influenzaNP, influenzaNA, influenzaM1, influenzaNS1)
paste(influenza, collapse = '')
```

1.  ¿Cuál es el tamaño de la secuencia?

    ```{r}
    length(influenza)
    ```

2.  ¿Cúal es la composición de nucleótidos?

    ```{r}
    (count(influenza, 1) / length(influenza) * 100)
    ```

3.  ¿Cuál es el contenido de GC?

    ```{r}
    (count(influenza, 2)[10] / length(influenza) * 100)
    ```

4.  Crear una función para obtener la secuencia en complementaria, ejemplo:\
    Virus original: agttgttagt ctacgtggac cgacaagaac\
    Complementaria: tcaacaatca gatgcacctg gctgttcttg

    ```{r}
    complementaria(influenza)
    ```

5.  Crear una gráfica de resumen para comparar la composición de nucleótidos:

    ```{r}
    barplot(table(influenza), col = 1:4)
    ```

6.  Resumen de todos los segmentos del virus H1N1 México 2009

    ```{r}
    segmentsH1N1 <- function(s1, s2, s3, s4, s5, s6, s7, s8){
      par(mfrow=c(2,4))
      barplot(table(s1), col = 1:4, main = "PB2", ylab = "Composición de Nucleótidos", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s2), col = 1:4, main = "PB1", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s3), col = 1:4, main = "PA", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s4), col = 1:4, main = "HA", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s5), col = 1:4, main = "NP", ylab = "Composición de Nucleótidos", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s6), col = 1:4, main = "NA", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s7), col = 1:4, main = "M1", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
      barplot(table(s8), col = 1:4, main = "NS1", names.arg = c("A", "C", "G", "T"), ylim = c(0, 1000))
    }
    segmentsH1N1(influenzaPB2, influenzaPB1, influenzaPA, influenzaHA, influenzaNP, influenzaNA, influenzaM1, influenzaNS1)
    ```

### Comparación 5 Viruses

```{r}
fiveViruses <- function(v1, v2, v3, v4, v5, v6){
  par(mfrow=c(2,3))
  barplot(table(v1), col = 1:4, main = "Zika", ylab = "Composición de Nucleótidos", names.arg = c("A", "C", "G", "T"), ylim = c(0, 9000))
  barplot(table(v2), col = 1:4, main = "SARS Coronavirus", names.arg = c("A", "C", "G", "T"), ylim = c(0, 9000))
  barplot(table(v3), col = 1:4, main = "Wuhan seafood pneumonia", names.arg = c("A", "C", "G", "T"), ylim = c(0, 9000))
  barplot(table(v4), col = 1:4, main = "Middle East coronavirus", ylab = "Composición de Nucleótidos", names.arg = c("A", "C", "G", "T"), ylim = c(0, 9000))
  barplot(table(v5), col = 1:4, main = "Dengue Virus 1", names.arg = c("A", "C", "G", "T"), ylim = c(0, 9000))
  barplot(table(v6), col = 1:4, main = "H1N1 Influenza A", names.arg = c("A", "C", "G", "T"), ylim = c(0, 9000))
}
fiveViruses(zikaVirus, coronaVirus, wuhanVirus, meast_hcov, dengue, influenza)
```
