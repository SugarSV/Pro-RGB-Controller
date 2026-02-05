# 🔥 Pro RGB Controller

Pro RGB Controller es un sistema de control de iluminación RGB para ventiladores de PC utilizando un **Arduino** y una **aplicación de escritorio precompilada**. Permite controlar de forma completa y suave los LEDs NeoPixel (WS2812B) de tus ventiladores, con múltiples efectos y velocidad configurable.

---

## 🎯 Funcionalidades

- Control total de color desde la PC  
- Múltiples efectos RGB suaves y profesionales:
  - Static (Estático)
  - Rainbow (Arcoíris suave)
  - Breathing (Respiración)
  - Pulse (Pulsante)
  - Cycle (Ciclo de colores)
  - Wave (Onda)
  - Flow (Flujo)
  - Chase (Persecución)
- Velocidad configurable de animaciones  
- Guardado del color seleccionado  
- Inicio automático con Windows  
- No requiere Python instalado (usa instalador `.exe`)  

---

## ⚙️ Cómo funciona

1. La app precompilada se comunica con el **Arduino** vía USB.  
2. El Arduino recibe comandos de color y efecto.  
3. El Arduino controla la tira NeoPixel dentro del ventilador.

---

## 🔧 Modificación del ventilador

1. Abrir el ventilador con cuidado.  
2. Identificar la tira de LEDs WS2812B (NeoPixel) y sus cables:  
   - **5V** → Alimentación  
   - **GND** → Tierra  
   - **DATA** → Señal  
3. Desconectar del controlador original (si existía).  

---

## 🔌 Conexiones con Arduino

| NeoPixel | Arduino |
|---------|--------|
| 5V | 5V |
| GND | GND |
| DATA | Pin D6 (puede cambiarse) |

**Recomendado:**  
- Resistencia de 330Ω entre DATA y Arduino  
- Capacitor de 1000µF entre 5V y GND  

---

## 💻 Instalador

El instalador precompilado `.exe`:

- Instala la aplicación en `C:\Program Files\Pro RGB Controller`  
- Crea acceso directo en el escritorio con icono personalizado  
- Inicia automáticamente con Windows  
- Pide permisos de administrador  

---

## 🚀 Ventajas

- Ultra ligero y eficiente  
- Compatible con cualquier PC  
- No depende de software o drivers de marca  
- Permite personalización avanzada de efectos  

---

## ⚠️ Advertencias

- Abrir el ventilador RGB implica riesgo físico.  
- Hazlo con cuidado y bajo tu responsabilidad.  

