from django import forms
from django.core.validators import validate_unicode_slug
from firstapp.models import CHOICES
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth.models import User
from .models import *

class suggestion_form(forms.Form):
    suggestion = forms.CharField(label='Post Title', max_length=140)
    image=forms.ImageField(label="Image File")
    # CHOICES = (('LFG', 'Lfg',), ('LFM', 'Lfm',),('WTS', 'Wtb',), ('WTS', 'Wts',))
    choice_field = forms.ChoiceField(widget=forms.Select(), choices=CHOICES)
    image_description=forms.CharField(label="Image Description", max_length=144)

    def save(self, request , commit=True):
        suggest = suggestion()
        suggest.suggestion=self.cleaned_data['suggestion']
        suggest.choice_field=self.cleaned_data['choice_field']
        suggest.image=self.cleaned_data['image']
        suggest.idescription=self.cleaned_data['image_description']
        suggest.author=request.user
        if commit:
            suggest.save()
        return suggest
    # work in progress
    # CHOICES = (('1', 'LFG',), ('2', 'LFM',), ('3', 'WTB',), ('4', 'WTS',))
    # choice_field = forms.ChoiceField(widget=forms.RadioSelect, choices=CHOICES)

class LoginForm(AuthenticationForm):
    username=forms.CharField(
        label="Username",
        max_length=30,
        widget=forms.TextInput(attrs={
            'name':'username'
        })
    )
    password=forms.CharField(
        label="Password",
        max_length=32,
        widget=forms.PasswordInput()
    )

class registration_form(UserCreationForm):
    email = forms.EmailField(
        label="Email",
        required=True
        )

    class Meta:
        model = User
        fields = ("username", "email",
            "password1", "password2")

    def save(self, commit=True):
        user=super(registration_form,self).save(commit=False)
        user.email=self.cleaned_data["email"]
        if commit:
            user.save()
        return user

class UserForm(forms.ModelForm):
   class Meta:
        model = User
        fields = ('first_name', 'last_name', 'email')

class ProfileForm(forms.ModelForm):
    class Meta:
        model = profile
        fields = ('bio', 'games', 'birth_date')
