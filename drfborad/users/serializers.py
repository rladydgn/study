from django.contrib.auth.models import User
from django.contrib.auth.password_validation import validate_password
from rest_framework import serializers
from rest_framework.validators import UniqueValidator

from users.models import Profile


class RegisterSerializer(serializers.ModelSerializer):
    # email 검증. 필수 요소, 유일한지 검증
    email = serializers.EmailField(
        required=True,
        validators=[UniqueValidator(queryset=User.objects.all())]
    )

    # 쓰기전용, 필수요소, password가 적합한지 검증
    password = serializers.CharField(
        # 역직렬화를 불가능하게.
        write_only=True,
        required=True,
        validators=[validate_password]
    )

    # 비밀번호 확인을 위해 사용하는 필드
    password2 = serializers.CharField(write_only=True, required=True)

    class Meta:
        model = User
        fields = ['username', 'password', 'password2', 'email']

    # 추가 인증. 비밀번호 확인에 사용 (validate_이름)하면 원하는 데이터 검증 가능
    def validate(self, attrs):
        # 비밀번호 확인이 다를 경우 에러 발생
        # 기존 검증 이후 추가 검증하는것임
        if attrs['password'] != attrs['password2']:
            raise serializers.ValidationError({"password": "password check is different"})
        return attrs

    # 모델 db에 저장
    def create(self, validated_data):
        user = User.objects.create_user(
            username=validated_data['username'],
            email=validated_data['email'],
            password=validated_data['password']
        )
        user.save()
        return user


class ProfileSerializer(serializers.ModelSerializer):
    class Meta:
        model = Profile
        fields = ['nickname', 'position', 'subjects', 'image']

# class RegisterSerializer(serializers.ModelSerializer):
#     email = serializers.EmailField(
#         required=True,
#         validators=[UniqueValidator(queryset=User.objects.all())],
#     )
#     password = serializers.CharField(
#         write_only=True,
#         required=True,
#         validators=[validate_password],
#     )
#     password2 = serializers.CharField(write_only=True, required=True)
#
#     class Meta:
#         model = User
#         fields = ('username', 'password', 'password2', 'email')
#
#     def validate(self, data):
#         if data['password'] != data['password2']:
#             raise serializers.ValidationError(
#                 {"password": "Password fields didn't match."})
#
#         return data
#
#     def create(self, validated_data):
#         user = User.objects.create_user(
#             username=validated_data['username'],
#             email=validated_data['email'],
#         )
#
#         user.set_password(validated_data['password'])
#         user.save()
#         return user
