<template>
  <v-layout>
    <v-flex xs12 sm6 offset-sm3>
    <v-form v-model="valid" ref="form" lazy-validation>
      Login
      <!--<v-text-field-->
        <!--label="Name"-->
        <!--v-model="name"-->
        <!--:rules="nameRules"-->
        <!--:counter="10"-->
        <!--required-->
      <!--&gt;</v-text-field>-->
      <v-text-field
        label="E-mail"
        v-model="email"
        :rules="emailRules"
        required
      ></v-text-field>
      <v-text-field
        label="Password"
        v-model="password"
        :rules="passwordRules"
        required
      ></v-text-field>
      <!--<v-select-->
      <!--label="Item"-->
      <!--v-model="select"-->
      <!--:items="items"-->
      <!--:rules="[v => !!v || 'Item is required']"-->
      <!--required-->
      <!--&gt;</v-select>-->
      <!--<v-checkbox-->
      <!--label="Do you agree?"-->
      <!--v-model="checkbox"-->
      <!--:rules="[v => !!v || 'You must agree to continue!']"-->
      <!--required-->
      <!--&gt;</v-checkbox>-->

      <v-btn
        @click="submit"
        :disabled="!valid"
      >
        login
      </v-btn>
      <v-btn @click="clear">clear</v-btn>
    </v-form>
    </v-flex>
  </v-layout>
</template>

<script>
  import firebase from 'firebase'
  // import axios from 'axios'

  export default {
    name: "login",
    data: () => ({
      valid: true,
      email: '',
      emailRules: [
        v => !!v || 'E-mail is required',
        v => /^\w+([.-]?\w+)*@\w+([.-]?\w+)*(\.\w{2,3})+$/.test(v) || 'E-mail must be valid'
      ],
      password: '',
      passwordRules: [
        v => !!v || 'Password is required'
      ]
    }),

    methods: {
      submit () {
        if (this.$refs.form.validate()) {
          firebase
            .auth()
            .signInWithEmailAndPassword(this.email, this.password)
            .then(
              user => {
                alert(`You are logged in as ${user.email} `);
                // this.$router.push('/');
                this.$router.go({ path: this.$router.path });
              },
              err => {
                alert(err.message);
              }
            );
          // Native form submission is not yet supported
          // axios.post('/api/submit', {
          //   name: this.name,
          //   email: this.email,
          // //  select: this.select,
          // //  checkbox: this.checkbox
          // })
          console.log("email", this.email);
          console.log("password", this.password);
        }
      },
      clear () {
        this.$refs.form.reset()
      }
    }
  }
</script>

<style scoped>

</style>
