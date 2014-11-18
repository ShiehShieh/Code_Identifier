# encoding: utf8
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name=b'Author',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                (b'first_name', models.CharField(max_length=30)),
                (b'last_name', models.CharField(max_length=40)),
                (b'email', models.EmailField(max_length=75)),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name=b'Publisher',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                (b'name', models.CharField(max_length=30)),
                (b'address', models.CharField(max_length=50)),
                (b'city', models.CharField(max_length=60)),
                (b'state_province', models.CharField(max_length=30)),
                (b'country', models.CharField(max_length=50)),
                (b'website', models.URLField()),
            ],
            options={
            },
            bases=(models.Model,),
        ),
        migrations.CreateModel(
            name=b'Book',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                (b'title', models.CharField(max_length=100)),
                (b'publisher', models.ForeignKey(to=b'books.Publisher', to_field='id')),
                (b'publication_date', models.DateField()),
                (b'authors', models.ManyToManyField(to=b'books.Author')),
            ],
            options={
            },
            bases=(models.Model,),
        ),
    ]
