# -*- coding: utf-8 -*-
# Generated by Django 1.11.5 on 2017-12-04 08:46
from __future__ import unicode_literals

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('firstapp', '0006_suggestion_choice_field'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='suggestion',
            name='choice_field',
        ),
    ]
