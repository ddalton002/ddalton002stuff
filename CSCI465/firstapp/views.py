from django.shortcuts import render, redirect
from django.contrib.auth.models import User
from django.http import HttpResponse, JsonResponse
from .models import *
from .forms import *
from django.contrib.auth.decorators import login_required
from django.db import transaction

# from django.contrib.auth.forms import UserCreationForm

# Create your views here.
def index(request):
    if request.method == 'POST':
        form = suggestion_form(request.POST)
        if form.is_valid():
            modentry = suggestion(suggestion=form.cleaned_data['suggestion'])
            modentry.save()
    else:
        form = suggestion_form()
    suggestions = suggestion.objects.all()
    context = {"variable":suggestions, "form":form}
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

def suggestions(request):
    suggestions = suggestion.objects.all()
    toReturn = {}
    toReturn["suggestions"]=[]
    for sugg in suggestions:
        toReturn["suggestions"]+=[{"suggest":sugg.suggestion}]
    return JsonResponse(toReturn)

@login_required
# @transaction.atomic
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
