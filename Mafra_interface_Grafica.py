import tkinter as tk
from tkinter.constants import COMMAND
from typing import Text
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# service account key JSON
cred = credentials.Certificate('serviceAccountKey.json')

firebase = firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://registromafra-default-rtdb.firebaseio.com/'
})
# TKINTER
tela = tk.Tk()
tela.title("MAFRA")

# dimensões da tela
largura = 1390
altura = 760

largura_screen = tela.winfo_screenwidth()
altura_screen = tela.winfo_screenheight()
posx = largura_screen/2 - largura/2
posy = altura_screen/2 - altura/2

# definir a geometry
tela.geometry("%dx%d+%d+%d" % (largura, altura, posx, posy))

# background da tela
imagem = tk.PhotoImage(file=r"./police1.png")
fundo = tk.Label(tela, image=imagem)
fundo.place(x=0, y=0)

# imprimir FIREBASE
ref = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/Nome')
print(ref.get())
ref2 = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/RG')
print(ref2.get())
ref3 = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/Telefone')
print(ref3.get())
ref4 = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/datadoalerta')
print(ref4.get())
ref5 = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/horario')
print(ref5.get())
ref6 = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/latitude')
print(ref6.get())
ref7 = db.reference('Registro/-MoBKZSHPKiekIU3aYoK/longitude')
print(ref7.get())
texto1 = ref.get()
label1 = tk.Label(tela, text=texto1, font="Arial 20 ",bg="medium aquamarine", fg="black")
label1.place(x=120, y=370)
texto2 = ref2.get()
label2 = tk.Label(tela, text=texto2, font="Arial 20 ",bg="medium aquamarine", fg="black")
label2.place(x=75, y=570)
texto3 = ref3.get()
label3 = tk.Label(tela, text=texto3, font="Arial 20 ", bg="medium aquamarine", fg="black")
label3.place(x=175, y=465)
texto4 = ref4.get()
label4 = tk.Label(tela, text=texto4, font="Arial 20 ",bg="medium aquamarine", fg="black")
label4.place(x=710, y=235)
texto5 = ref5.get()
label5 = tk.Label(tela, text=texto5, font="Arial 20 ",bg="medium aquamarine", fg="black")
label5.place(x=710, y=370)
texto6 = ref6.get()
label6 = tk.Label(tela, text=texto6, font="Arial 20 ", bg="medium aquamarine", fg="black")
label6.place(x=680, y=510)
texto7 = ref7.get()
label7 = tk.Label(tela, text=texto7, font="Arial 20 ",bg="medium aquamarine", fg="black")
label7.place(x=680, y=560)
tela.mainloop()
