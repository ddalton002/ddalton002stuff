from django.db import models
from django import forms
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver

# Create your models here.
class suggestion(models.Model):
    suggestion = models.CharField(max_length=141)
    author = models.ForeignKey(User, on_delete=models.CASCADE)
    authored = models.DateTimeField(auto_now=True)
    LFG = 'Lfg'
    LFM = 'Lfm'
    WTB = 'Wtb'
    WTS = 'Wts'
    CHOICES = ((LFG, 'Lfg',), (LFM, 'Lfm',),(WTB, 'Wtb',), (WTS, 'Wts',))
    choice_field = models.CharField(max_length=3, choices=CHOICES, default=LFG,)
    image = models.ImageField(max_length=144, upload_to='uploads/%Y/%m/%d/')
    idescription = models.CharField(max_length=144)
    def __str__(self):
        return self.suggestion

class profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    bio = models.TextField(null=True, max_length=500, blank=True)
    games = models.CharField(null=True, max_length=140, blank=True)
    birth_date = models.DateField(null=True, blank=True)

    # def __str__(self):
    #     return self.profile

@receiver(post_save, sender=User)
def create_user_profile(sender, instance, created, **kwargs):
    if created:
        profile.objects.create(user=instance)

@receiver(post_save, sender=User)
def save_user_profile(sender, instance, **kwargs):
    instance.profile.save()
