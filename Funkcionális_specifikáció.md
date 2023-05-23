# Funkcionális specifikáció

## 1. Vágyálomrendszer leírása

A projektünk egy időjárás állomás, amely különböző pillanatnyi időjárás adatokat ír ki egy lcd kijelzőre.

## 2. Alkatrész lista:

### Minden alkatrész be lett szerezve

* 1db TMP36 hőmérsékletszenzor
* 1db Piezo
* 1db Talajnedvesség érzékelő
* 1db LCD 16x2
* 1db Fotoellenállás
* 1db Szabályozható ellenállás
* 6db 220(Ohm) ellenállás
* 1db 10(kOmh) ellenállás
* 2db Kék led
* 2db Zöld led
* 2db Sárga led
* 2db Narancssárga led
* 2db Piros led
* jumper kábelek

## 3. Használati esetek (működés)

* Áram alá helyezés után a szenzorok által mért adatokat automatikusan megjeleníti a kijelző
  
## 4. Képernyőtervek (sematikus rajz és CAD tervrajz)


### 4.1: Sematikus rajz:

![SematikusRajz](https://github.com/Safran3k/2023_robotika_beadando/blob/main/img/Semantikus_Rajz1.png)

![SematikusRajz](https://github.com/Safran3k/2023_robotika_beadando/blob/main/img/Semantikus_Rajz2.png)
 
### 4.2: CAD tervrajz:

![CADRajz](https://github.com/Safran3k/2023_robotika_beadando/blob/main/img/TinkerCad_tervrajz.png)

## 5. Forgatókönyvek (állapotátmenet gráf)

### 5.1: jelölések

#### 5.1.1 Állapotok jelölése:
 
 * A hőmérsékle értéke alapján:
   * h<15 °C: csak a kék ledek világítanak
   * h>=15 °C: a kék és a zöld ledek világítanak
   * h>=23 °C: a kék, a zöld és a sárga ledek világítanak
   * h>=23 °C: a kék, a zöld, sárga és a narancssárga ledek világítanak
   * h>=28 °C: a kék, a zöld, sárga és a narancssárga ledek világítanak
   * h>33 °C: az összes led vidágít
   * h>38 °C: Hangjelzést ad
 * A környezeti fény alapján:
   * f<85: Kiírja hogy: Cloudy
   * f>=85: Kiírja hogy: Scattered clouds
   * f>=170: Kiírja hogy: Sunny
 * A levegő páratartalma alapján:
   * Kiírja a pára tartalmát
   * (A program korlátoltságai miatt a páratartalom mérő eszköz helyett egy talajnedvességmérőt használunk)

#### 5.2 Állapot átmenet gráf
![CADRajz](https://github.com/Safran3k/2023_robotika_beadando/blob/main/img/%C3%81llapot%C3%A1tmenetRajz.png)
  
