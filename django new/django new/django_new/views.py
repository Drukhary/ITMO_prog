"""
Definition of views.
"""

from django.http import HttpResponse
from django.shortcuts import render
import json




with open("json_data.json", 'r') as read_file:
    data = json.load(read_file)
    
    name = data['name']

    head_name = data['head']['name']
    head_surname = data['head']['surname']

    
    index = data['location']['index']
    city = data['location']['city']
    adress = data['location']['adress']

    
    ad_amount = len(data['administrative'])

    
    sc_amount = len(data['scintific_and_educational'])

    
    mf_amount = 0
    for i in data['scintific_and_educational']:
        if i['name'].find("Мегафакультет") != -1:
            mf_amount += 1

    meg_id= data['scintific_and_educational'][0]['id']

    meg_name=data['scintific_and_educational'][0]['name']

    megITMO = {'meg_id': meg_id,
               'meg_name':meg_name}

    dep_amount = 0
    for i in data['scintific_and_educational']:
        dep_amount += len(i['departments'])


    

    edp_id = data['scintific_and_educational'][0]['departments'][0]['educational_programs'][0]['id']

    
    edp_name = data['scintific_and_educational'][0]['departments'][0]['educational_programs'][0]['name']

    
    dis_name = data['scintific_and_educational'][0]['departments'][0]['educational_programs'][0]['discipline']

    
    year_of_study = data['scintific_and_educational'][0]['departments'][0]['educational_programs'][0]['year']

    
    administrative = data['administrative']

    
    amount_of_groups = len(year_of_study['groups'])

    
    group = year_of_study['groups'][0]

    
    deps = data['scintific_and_educational'][0]['departments']


    
    dict_ITMO = {'name': name, 'head': [head_name, head_surname],
            'adress': {'index': index, 'city': city, 'adress': adress},
            'ad_amount': ad_amount,
            'sc_amount': sc_amount,
            'mf_amount': mf_amount,
            'dep_amount': dep_amount}

    
    dict_disc = {
                 'edp_id': edp_id,
                 'edp_name': edp_name,
                 'dis_name': dis_name,
                 'year_of_study': year_of_study,
                 'amount_of_groups': amount_of_groups}

    
    dict_group = {'group': group}

    
    dict_deps = {'departaments': deps}

    
    dict_uni = {'administrative': administrative}
    dict_uni.update(megITMO)
 
    dict_uni.update(dict_deps)
    
    dict_uni.update(dict_ITMO)


def index(request):
    return HttpResponse("Hello, World!")
def indexRender(request):
    return render(request, 'index.html', {})
def ITMO_University(request):
    return render(request, 'universityInfo.html', dict_ITMO)
def disc(request):
    return render(request, 'disciplineInfo.html', dict_disc)
def group(request):
    return render(request, 'groupsInfo.html', dict_group)
def deps(request):
    return render(request, 'departamentsInfo.html', dict_deps)
def ITMO_structure(request):
    return render(request, 'universityStructure.html', dict_uni)
