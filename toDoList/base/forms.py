from django import forms

from base.models import Todo


# title = models.CharField(max_length=50)
# description = models.TextField()
# important = models.BooleanField(default=False)
class ToDoForm(forms.ModelForm):
    class Meta:
        model = Todo
        fields = ('title', 'description', 'important')
