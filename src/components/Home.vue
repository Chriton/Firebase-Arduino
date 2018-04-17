<template>
  <v-container>
    <v-layout row wrap>
      <v-flex xs-12 sm6 class="text-xs-center text-sm-right">
        <v-btn large to="/sensor" class="info">Explore Sensor Data</v-btn>
      </v-flex>
      <v-flex xs-12 sm6 class="text-xs-center text-sm-left">
        <v-btn large to="/sensor" class="info">Organise Sensor Data</v-btn>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script>
  export default {
    name: "home"
  }
</script>

<style scoped>

</style>
