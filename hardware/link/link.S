.text
.global _start
_start:       
          b   step1
step1:
          ldr pc, =step2
step2:
  b step2
