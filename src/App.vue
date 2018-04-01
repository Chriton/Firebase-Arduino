<template>
  <v-app>
    <Navbar/>
    <main>
      <router-view></router-view>
    </main>
    <Footer/>
  </v-app>
</template>


<script>
  import Navbar from '@/components/Navbar'
  import Footer from '@/components/Footer'

  export default {
    name: 'App',
    components: {
      Navbar,
      Footer
    }
  }
</script>
