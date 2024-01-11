## Välkommen till ☄️ Asteroid Kitty!

Asteroid Kitty är ett spännande och utmanande arkadspel där spelaren styr en katt genom en asteroidregnskur i en öken. Målet är att undvika kollisioner med asteroiderna för att överleva så länge som möjligt.

### Mål:
- Guida katten genom ett asteroidregn utan att kollidera.

### Hur man spelar:
1. Kör programmet.
2. Använd piltangenterna eller musen för att röra katten åt vänster eller höger.
3. Undvik asteroider genom att navigera mellan dem.
4. Spelet är över om katten träffas av en asteroid tre gånger.

### Spelbeskrivning:
- Spelet har en bakgrundsbild och fyra sprites. Huvudfiguren är "Kitty" och det finns en asteroid-sprite ("Asteroid").
- När programmet körs, visas bakgrundsbilden ("backdrop1") med "Kitty" mitt på skärmen och spelet startar.
- "Asteroid" börjar falla slumpmässigt från skärmens topp varje sekund.
- "Kitty" kan flyttas åt vänster och höger med antingen musen eller tangentbordets piltangenter.
- Om "Kitty" vidrör "Asteroid" en gång, dör "Kitty" och spelet är över.
- Efter 5 sekunder från spelets start, börjar en annan "Asteroid" falla slumpmässigt från toppen varje 0,5 sekund.
- Efter 10 sekunder från start, börjar en ytterligare "Asteroid" falla slumpmässigt varje 0,25 sekund.

### Resurser, bilder:
- asteroid1.png
- backdrop1.png
- kitty1.png

## Systemkrav och Beskrivning:
Programmet är skrivet i C++ och använder SDL2-biblioteket för grafik. Det är objektorienterat och indelat i klasser som använder tekniker som inkapsling, arv och polymorfism.

### Filstruktur vid inlämning:
```
project.zip
project/
├── .vscode/ (om VSCode används)
├── Makefile (om programmet byggs med "make")
├── doc/ (för Dokumentation och Rapport)
├── build/
│   └── debug/ (ditt kompilerade program)
├── include/ (för header-filer, ".h")
│   └── Constants.h (gResPath, sökväg till 'resources/')
├── lib/ (för egna bibliotek)
├── resources/ (bilder, typsnitt, ljud)
│   ├── fonts/
│   ├── images/
│   └── sounds/
└── src/ (för ".cpp"-filer för kompilering)
```

### Speciella Krav på Kod:
- Använd `constants::gResPath` för sökvägar till resursfiler.
- Förhindra minnesläckage och säkerställ att dynamiskt allokerat minne städas upp.

### Spelmotorn:
- "GameEngine"-klassen hanterar huvudloopen och sprite-hantering.
- Enkel kollisionsdetektering och möjlighet att sätta frame rate.

### Session:
- Hanterar spel-sessioner och startar nya spel.

### System:
- Initialiserar och hanterar SDL2-relaterade uppgifter som fönster och rendering.

### Sprite och dess Subklasser:
- "Sprite"-klassen är en bas för alla rörliga figurer.
- "Kitty" och "Asteroid" är subklasser med specifika beteenden.

### Spelregler:
- Spelaren kontrollerar "Kitty" för att undvika kollisioner med fallande asteroider.
- En träff resulterar i game over.

För mer detaljerad information om kodstruktur och specifika klasser, se kommentarer i källkoden.

---

Lycka till och ha kul med ☄️ Asteroid Kitty! 🐱💫
