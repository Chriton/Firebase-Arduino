<template>
  <v-container>
    <v-layout row wrap>
      <v-flex xs12 sm10 md8 offset-sm1 offset-md2>
          <v-card class="mb-2">
          <v-container fluid>
            <v-layout row>
              <v-flex xs5 sm4 md3>
                <v-card-media
                  src="http://via.placeholder.com/300x150"
                  height="130px">
                </v-card-media>
              </v-flex>
              <v-flex xs7 sm8 md9>
                <v-card-title primary-title>
                  <div>
                    <h5 class="headline mb-0 info--text" >Sensor 1 data</h5>
                    <div>some random subtitle...</div>
                  </div>
                </v-card-title>
                <v-card-actions>
                  <v-spacer></v-spacer>
                  <v-btn flat class="info">
                    <v-icon left light>arrow_forward</v-icon>View Sensor
                  </v-btn>
                </v-card-actions>
              </v-flex>
            </v-layout>
          </v-container>
        </v-card>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script>
  export default {
    name: "sensor",
    computed: {}
  }
</script>

<style scoped>

</style>
