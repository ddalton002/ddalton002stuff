from django.shortcuts import render, redirect
from django.contrib.auth.models import User
from django.http import HttpResponse, JsonResponse
from .models import *
from .forms import *
from django.contrib.auth.decorators import login_required
from django.db import transaction
from django.contrib.postgres.search import SearchQuery, SearchRank, SearchVector
from django.views.generic import ListView

# from django.contrib.auth.forms import UserCreationForm

# Create your views here.
def index(request):
    form = suggestion_form()
    suggestions = suggestion.objects.all().order_by('-authored')
    to_return = []
    for suggest in suggestions:
        data = {}
        data["suggestion"]=suggest.suggestion
        data["image"]=suggest.image
        data["idescription"]=suggest.idescription
        data["author"]=suggest.author
        # data["comments"]=[]
        data["id"]=suggest.id
    #     comments = comment.objects.all().filter(suggestion=suggest).order_by('-authored')
    #     for comm in comments:
    #         data["comments"]+=[{"comment":comm.comment, "author":comm.author}]
    # , "comment_form":c_form
        to_return+=[data]
    context = {"suggestions":to_return, "form":form}
    return render(request,"default.html",context)


def page2(request):
    suggestions = suggestion.objects.all()
    toReturn = ""
    for sugg in suggestions:
        toReturn += sugg.suggestion + " "
    context = {"variable":toReturn}
    return render(request,"default.html",context)

def register(request):
    if request.method == 'POST':
        form = registration_form(request.POST)
        if form.is_valid():
            form.save(commit=True)
            return redirect("/")
    else:
        form = registration_form()
    context = {"form":form}
    return render(request,"register.html",context)

def lfg(request):
    form = suggestion_form()
    suggestions = suggestion.objects.filter(suggestion='hat')
    to_return = []
    for suggest in suggestions:
        data = {}
        data["suggestion"]=suggest.suggestion
        data["image"]=suggest.image
        data["idescription"]=suggest.idescription
        data["author"]=suggest.author
        data["id"]=suggest.id
        to_return+=[data]
    context = {"suggestions":to_return, "form":form}
    return render(request,"default.html",context)

def lfm(request):
    form = suggestion_form()
    suggestions = suggestion.objects.filter(suggestion='hat')
    to_return = []
    for suggest in suggestions:
        data = {}
        data["suggestion"]=suggest.suggestion
        data["image"]=suggest.image
        data["idescription"]=suggest.idescription
        data["author"]=suggest.author
        data["id"]=suggest.id
        to_return+=[data]
    context = {"suggestions":to_return, "form":form}
    return render(request,"default.html",context)

def wtb(request):
    form = suggestion_form()
    suggestions = suggestion.objects.filter(suggestion='hat')
    to_return = []
    for suggest in suggestions:
        data = {}
        data["suggestion"]=suggest.suggestion
        data["image"]=suggest.image
        data["idescription"]=suggest.idescription
        data["author"]=suggest.author
        data["id"]=suggest.id
        to_return+=[data]
    context = {"suggestions":to_return, "form":form}
    return render(request,"default.html",context)

def wts(request):
    form = suggestion_form()
    suggestions = suggestion.objects.filter(suggestion='hat')
    to_return = []
    for suggest in suggestions:
        data = {}
        data["suggestion"]=suggest.suggestion
        data["image"]=suggest.image
        data["idescription"]=suggest.idescription
        data["author"]=suggest.author
        data["id"]=suggest.id
        to_return+=[data]
    context = {"suggestions":to_return, "form":form}
    return render(request,"default.html",context)

# Source https://simpleisbetterthancomplex.com/tutorial/2016/07/22/how-to-extend-django-user-model.html
@login_required
def profile(request):
    if request.method == 'POST':
        user_form = UserForm(request.POST, instance=request.user)
        profile_form = ProfileForm(request.POST, instance=request.user.profile)
        if user_form.is_valid() and profile_form.is_valid():
            user_form.save()
            profile_form.save()
            return redirect('.')
        # else:
        #     messages.error(request, _('Please correct the error below.'))
    else:
        user_form = UserForm(instance=request.user)
        profile_form = ProfileForm(instance=request.user.profile)
    return render(request, 'profile.html', {
        'user_form': user_form,
        'profile_form': profile_form
    })

@login_required
def suggestion_view(request):
    if request.method == 'POST':
        if request.user.is_authenticated:
            form = suggestion_form(request.POST, request.FILES)
            if form.is_valid():
                form.save(request)
                return redirect("/")
        else:
            form=suggestion_form()
    else:
        form = suggestion_form()
    context = {"form":form}
    return render(request,"suggest.html",context)

def suggestions(request):
    suggestions = suggestion.objects.all() #.order_by('-authored')
    toReturn = {}
    toReturn["suggestions"]=[]
    # toReturn["haha"]=[]
    for sugg in suggestions:
        toReturn["suggestions"]+=[{"suggest":sugg.suggestion}]
    return JsonResponse(toReturn)
